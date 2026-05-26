#!/usr/bin/env python3
"""
Pass 3: Handle remaining sections without Tiny Code headings.
Strategy: extract first C block with int main, or first C block.
"""
import re
import os

PROJECT = "/Users/apple/github/the-litte-book-of/c"
SECTIONS_DIR = os.path.join(PROJECT, "books/en-US/sections")
SRC_DIR = os.path.join(PROJECT, "src")

# Sections to process in this pass
TODO = [39, 43, 50, 57, 58, 60, 80]
# s02 genuinely only has bash code - skip


def section_to_chapter(n: int) -> int:
    if n <= 9:
        return 1
    return (n - 1) // 10 + 1


def find_all_c_blocks(lines: list[str]) -> list[tuple[int, int]]:
    """Return list of (start, end) line indices for all ```c ... ``` blocks."""
    blocks = []
    start = None
    for i, line in enumerate(lines):
        stripped = line.rstrip()
        if re.match(r"^```c\b", stripped) and start is None:
            start = i
        elif stripped == "```" and start is not None:
            blocks.append((start, i))
            start = None
    return blocks


def block_code(lines: list[str], start: int, end: int) -> str:
    return "".join(lines[start + 1:end])


def process(sec_num: int) -> str:
    ch_num = section_to_chapter(sec_num)
    section_file = os.path.join(SECTIONS_DIR, f"s{sec_num:02d}.md")
    if not os.path.exists(section_file):
        section_file = os.path.join(SECTIONS_DIR, f"s{sec_num:03d}.md")
    if not os.path.exists(section_file):
        return f"s{sec_num:02d}: FILE NOT FOUND"

    with open(section_file, encoding="utf-8") as f:
        lines = f.readlines()

    blocks = find_all_c_blocks(lines)
    if not blocks:
        return f"s{sec_num:02d}: NO C blocks at all"

    # Prefer first block with int main
    chosen = None
    for start, end in blocks:
        code = block_code(lines, start, end)
        if "int main" in code:
            chosen = (start, end, code)
            break

    if chosen is None:
        # Fallback: first C block
        start, end = blocks[0]
        code = block_code(lines, start, end)
        chosen = (start, end, code)

    start, end, code = chosen

    # Write main.c
    src_dir = os.path.join(SRC_DIR, f"ch{ch_num:02d}", f"s{sec_num:02d}")
    os.makedirs(src_dir, exist_ok=True)
    main_c = os.path.join(src_dir, "main.c")
    with open(main_c, "w", encoding="utf-8") as f:
        f.write(code)

    # Replace in section file
    include_path = f"../../../src/ch{ch_num:02d}/s{sec_num:02d}/main.c"
    new_lines = (
        lines[:start]
        + [f'```{{.c include="{include_path}"}}\n', "```\n"]
        + lines[end + 1:]
    )
    with open(section_file, "w", encoding="utf-8") as f:
        f.writelines(new_lines)

    has_main = "int main" in code
    return f"s{sec_num:02d}: OK (has_main={has_main}) → {main_c}"


def main():
    for n in TODO:
        print(process(n))
    print("\nPass 3 done.")


if __name__ == "__main__":
    main()
