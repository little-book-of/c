#!/usr/bin/env python3
"""
Second pass: fix sections that missed code extraction.
Handles '#### Step N. Tiny Code: ...' and other heading variants.
Also handles sections with no C code at all (bash-only or no code block).
"""
import re
import os

PROJECT = "/Users/apple/github/the-litte-book-of/c"
SECTIONS_DIR = os.path.join(PROJECT, "books/en-US/sections")
SRC_DIR = os.path.join(PROJECT, "src")

# Sections we know were already extracted correctly (from pass 1)
ALREADY_DONE = {
    1, 3, 4, 5, 6, 7, 8, 9,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 40,
    41, 42, 44, 45, 46, 47, 48, 49,
    51, 52, 53, 54, 55, 56, 59,
    61, 62, 63, 64, 65, 66, 68,
}

# Sections with no relevant C code (bash-only "Tiny Code", or no main.c)
BASH_ONLY = {2}  # "Installing a C Compiler" - only bash/shell commands


def section_to_chapter(n: int) -> int:
    if n <= 9:
        return 1
    return (n - 1) // 10 + 1


def find_tiny_code_block(lines: list[str]) -> tuple[int, int] | None:
    """
    Find the first C code block after any '#### ...Tiny Code...' heading.
    Returns (start_idx, end_idx) of the lines INCLUDING the fence lines,
    or None if not found.
    """
    tiny_re = re.compile(r"^####.*Tiny Code", re.IGNORECASE)
    in_tiny = False

    for i, line in enumerate(lines):
        stripped = line.rstrip()
        if tiny_re.match(stripped):
            in_tiny = True
            continue

        if in_tiny:
            if re.match(r"^```c\b", stripped):
                # Found start of C block
                start = i
                for j in range(i + 1, len(lines)):
                    if lines[j].rstrip() == "```":
                        return (start, j)
                return None  # unclosed block
            elif re.match(r"^####", stripped) or re.match(r"^###", stripped):
                # Next subsection without finding C block
                break

    return None


def extract_code(lines: list[str], start: int, end: int) -> str:
    """Return the code between the fences (exclusive)."""
    return "".join(lines[start + 1:end])


def replace_block(lines: list[str], start: int, end: int, include_path: str) -> list[str]:
    """Replace lines[start..end] (inclusive) with Quarto include."""
    return (
        lines[:start]
        + [f'```{{.c include="{include_path}"}}\n', "```\n"]
        + lines[end + 1:]
    )


def process_section(sec_num: int) -> str:
    """
    Process one section file. Returns status message.
    """
    ch_num = section_to_chapter(sec_num)
    section_file = os.path.join(SECTIONS_DIR, f"s{sec_num:02d}.md")

    if not os.path.exists(section_file):
        # Try three-digit name
        section_file = os.path.join(SECTIONS_DIR, f"s{sec_num:03d}.md")
        if not os.path.exists(section_file):
            return f"s{sec_num:02d}: MISSING FILE"

    with open(section_file, encoding="utf-8") as f:
        lines = f.readlines()

    result = find_tiny_code_block(lines)
    if result is None:
        return f"s{sec_num:02d}: NO C code block found (bash-only or no Tiny Code)"

    start, end = result
    code = extract_code(lines, start, end)

    if not code.strip():
        return f"s{sec_num:02d}: EMPTY code block"

    # Write main.c
    src_dir = os.path.join(SRC_DIR, f"ch{ch_num:02d}", f"s{sec_num:02d}")
    os.makedirs(src_dir, exist_ok=True)
    main_c = os.path.join(src_dir, "main.c")
    with open(main_c, "w", encoding="utf-8") as f:
        f.write(code)

    # Replace in section file
    # For sections in SECTIONS_DIR, section files are at:
    # books/en-US/sections/sNN.md
    # src files at: src/chNN/sNN/main.c
    # Relative path from section file: ../../../src/chNN/sNN/main.c
    include_path = f"../../../src/ch{ch_num:02d}/s{sec_num:02d}/main.c"
    new_lines = replace_block(lines, start, end, include_path)

    with open(section_file, "w", encoding="utf-8") as f:
        f.writelines(new_lines)

    return f"s{sec_num:02d}: OK → {main_c}"


def main():
    # All section numbers in the book (section 10 doesn't exist)
    all_sections = list(range(1, 10)) + list(range(11, 101))

    # Process those that weren't done in pass 1
    todo = [n for n in all_sections if n not in ALREADY_DONE]
    print(f"Pass 2: processing {len(todo)} sections\n")

    no_code = []
    for n in todo:
        status = process_section(n)
        print(f"  {status}")
        if "NO C code" in status or "bash-only" in status:
            no_code.append(n)

    print(f"\nSections with no extractable C code: {sorted(no_code)}")
    print("Pass 2 done.")


if __name__ == "__main__":
    main()
