#!/usr/bin/env python3
"""
Split book.md into:
  - books/en-US/sections/s{NN}.md  (one per section)
  - src/ch{NN}/s{NN}/main.c        (Tiny Code block per section)
  - books/en-US/book.md            (rebuilt with {{< include >}} directives)
  - ~/notes/Spec/1900/19{5X}.md    (factual review specs, one per chapter)
"""

import re
import os
import sys

PROJECT = "/Users/apple/github/the-litte-book-of/c"
BOOK_PATH = os.path.join(PROJECT, "books/en-US/book.md")
SECTIONS_DIR = os.path.join(PROJECT, "books/en-US/sections")
SRC_DIR = os.path.join(PROJECT, "src")
SPEC_DIR = os.path.expanduser("~/notes/Spec/1900")
SPEC_START = 1956  # first spec number to use


def section_to_chapter(n: int) -> int:
    if n <= 9:
        return 1
    return (n - 1) // 10 + 1


def parse_book(path: str):
    """
    Return:
      preamble_lines  - lines before the first chapter heading
      chapters        - list of {num, title, header_line}
      sections        - list of {num, chapter, title, lines}
    where sections[i].lines include the ### heading line but NOT the chapter heading.
    Chapter heading lines are stored separately in chapters[].
    """
    with open(path, encoding="utf-8") as f:
        lines = f.readlines()

    chapter_re = re.compile(r"^# Chapter (\d+)\.\s*(.*)")
    section_re = re.compile(r"^### (\d+)\.\s*(.*)")

    preamble = []
    chapters = []
    sections = []

    current_chapter = None
    current_section = None
    section_lines = []
    # chapter_header_lines maps chapter num -> header line string
    chapter_headers = {}

    in_section = False
    in_preamble = True

    for line in lines:
        cm = chapter_re.match(line)
        sm = section_re.match(line)

        if cm:
            ch_num = int(cm.group(1))
            ch_title = cm.group(2).strip()
            if in_section and current_section is not None:
                sections.append(
                    {
                        "num": current_section,
                        "chapter": section_to_chapter(current_section),
                        "title": section_title,
                        "lines": section_lines,
                    }
                )
                section_lines = []
                in_section = False
            current_chapter = ch_num
            chapters.append(
                {"num": ch_num, "title": ch_title, "header_line": line}
            )
            chapter_headers[ch_num] = line
            in_preamble = False
        elif sm:
            sec_num = int(sm.group(1))
            sec_title = sm.group(2).strip()
            if in_section and current_section is not None:
                sections.append(
                    {
                        "num": current_section,
                        "chapter": section_to_chapter(current_section),
                        "title": section_title,
                        "lines": section_lines,
                    }
                )
            current_section = sec_num
            section_title = sec_title
            section_lines = [line]
            in_section = True
            in_preamble = False
        else:
            if in_preamble:
                preamble.append(line)
            elif in_section:
                section_lines.append(line)

    if in_section and section_lines:
        sections.append(
            {
                "num": current_section,
                "chapter": section_to_chapter(current_section),
                "title": section_title,
                "lines": section_lines,
            }
        )

    return preamble, chapters, sections


# ---------------------------------------------------------------------------
# Code extraction
# ---------------------------------------------------------------------------

def extract_tiny_code(lines: list[str]) -> str | None:
    """Return the content of the first ```c block after '#### Tiny Code'."""
    in_tiny = False
    in_block = False
    code = []

    for line in lines:
        stripped = line.rstrip()
        if re.match(r"^#### Tiny Code", stripped):
            in_tiny = True
            continue

        if in_tiny:
            if re.match(r"^```c\b", stripped) and not in_block:
                in_block = True
                code = []
                continue
            elif stripped == "```" and in_block:
                return "".join(code)
            elif in_block:
                code.append(line)
            elif re.match(r"^####", stripped):
                # Another subsection — Tiny Code had no c block
                break

    return None


def replace_tiny_code_block(lines: list[str], include_path: str) -> list[str]:
    """Replace the ```c ... ``` block inside Tiny Code with a Quarto include."""
    in_tiny = False
    in_block = False
    replaced = False
    out = []

    for line in lines:
        stripped = line.rstrip()

        if re.match(r"^#### Tiny Code", stripped):
            in_tiny = True
            out.append(line)
            continue

        if in_tiny and not replaced:
            if re.match(r"^```c\b", stripped) and not in_block:
                in_block = True
                continue
            elif stripped == "```" and in_block:
                in_block = False
                out.append(f'```{{.c include="{include_path}"}}\n')
                out.append("```\n")
                replaced = True
                in_tiny = False
                continue
            elif in_block:
                continue  # skip original code lines (file now holds them)
            else:
                out.append(line)
        else:
            out.append(line)

    return out


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    os.makedirs(SECTIONS_DIR, exist_ok=True)
    os.makedirs(SPEC_DIR, exist_ok=True)

    preamble, chapters, sections = parse_book(BOOK_PATH)

    print(f"Parsed: {len(chapters)} chapters, {len(sections)} sections")

    # Group sections by chapter for the rebuilt book.md and spec files
    sections_by_chapter: dict[int, list] = {}
    for sec in sections:
        sections_by_chapter.setdefault(sec["chapter"], []).append(sec)

    # -----------------------------------------------------------------------
    # Write section files + extract main.c files
    # -----------------------------------------------------------------------
    extraction_results = {}  # sec_num -> (code_extracted: bool, issues: list[str])

    for sec in sections:
        sec_num = sec["num"]
        ch_num = sec["chapter"]
        sec_lines = sec["lines"]

        # -- Extract Tiny Code --
        tiny_code = extract_tiny_code(sec_lines)

        src_subdir = os.path.join(SRC_DIR, f"ch{ch_num:02d}", f"s{sec_num:02d}")
        os.makedirs(src_subdir, exist_ok=True)

        include_path = f"../../../src/ch{ch_num:02d}/s{sec_num:02d}/main.c"
        issues = []

        if tiny_code:
            main_c_path = os.path.join(src_subdir, "main.c")
            with open(main_c_path, "w", encoding="utf-8") as f:
                f.write(tiny_code)
            new_lines = replace_tiny_code_block(sec_lines, include_path)
            code_extracted = True
        else:
            new_lines = sec_lines
            code_extracted = False
            issues.append("No Tiny Code C block found")

        extraction_results[sec_num] = {
            "extracted": code_extracted,
            "issues": issues,
            "ch": ch_num,
        }

        # -- Write section file --
        section_file = os.path.join(SECTIONS_DIR, f"s{sec_num:02d}.md")
        with open(section_file, "w", encoding="utf-8") as f:
            f.writelines(new_lines)

        print(f"  s{sec_num:02d} → {section_file}  (code: {'yes' if code_extracted else 'NO'})")

    # -----------------------------------------------------------------------
    # Rebuild book.md
    # -----------------------------------------------------------------------
    new_book_lines = list(preamble)

    for ch in sorted(chapters, key=lambda x: x["num"]):
        ch_num = ch["num"]
        new_book_lines.append("\n")
        new_book_lines.append(ch["header_line"])
        new_book_lines.append("\n")

        for sec in sorted(sections_by_chapter.get(ch_num, []), key=lambda x: x["num"]):
            sec_num = sec["num"]
            rel_path = f"sections/s{sec_num:02d}.md"
            new_book_lines.append(f"{{{{< include {rel_path} >}}}}\n")
            new_book_lines.append("\n")

    with open(BOOK_PATH, "w", encoding="utf-8") as f:
        f.writelines(new_book_lines)
    print(f"\nRebuilt: {BOOK_PATH}")

    # -----------------------------------------------------------------------
    # Summary report
    # -----------------------------------------------------------------------
    no_code = [n for n, r in extraction_results.items() if not r["extracted"]]
    print(f"\nSections without Tiny Code block: {sorted(no_code)}")
    print(f"\nDone. {len(sections)} section files written.")
    print(f"src/ tree created under: {SRC_DIR}")


if __name__ == "__main__":
    main()
