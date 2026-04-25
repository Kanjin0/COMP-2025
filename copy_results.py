#!/usr/bin/env python3
"""
Process compiler test files: for each .java file, compare .out (expected)
with .out_temp (current). Generate a report ONLY for tests that FAIL
(i.e., outputs differ or a file is missing).
"""

import os
import sys
from pathlib import Path

def read_file_content(file_path: Path) -> str:
    """Read a text file and return its content, or an error message."""
    try:
        return file_path.read_text(encoding='utf-8')
    except Exception as e:
        return f"[ERROR reading file: {e}]"

def test_passed(expected_path: Path, current_path: Path) -> bool:
    """
    Determine if a test passes: both expected and current files exist
    and their contents are identical (exact match, including whitespace).
    """
    if not expected_path.exists() or not current_path.exists():
        return False
    expected_content = read_file_content(expected_path)
    current_content = read_file_content(current_path)
    # Avoid false positives from read errors
    if expected_content.startswith("[ERROR") or current_content.startswith("[ERROR"):
        return False
    return expected_content == current_content

def process_folder(folder_path: Path, output_file: Path, only_failing: bool = True) -> None:
    """
    Scan folder for .java files and write a report.
    If only_failing is True, only include test cases that do NOT pass.
    """
    java_files = list(folder_path.glob("*.java")) + list(folder_path.glob("*.Java"))
    if not java_files:
        print(f"No .java files found in {folder_path}")
        return

    java_files.sort()
    failing_count = 0
    total_count = len(java_files)

    with open(output_file, 'w', encoding='utf-8') as out:
        for java_path in java_files:
            base_name = java_path.stem
            expected_path = folder_path / f"{base_name}.out"
            current_path = folder_path / f"{base_name}.out_temp"

            passed = test_passed(expected_path, current_path)

            if only_failing and passed:
                continue  # Skip passing tests

            failing_count += 1

            out.write(f"file: {java_path.name}\n")
            out.write("code of the file:\n")
            out.write(read_file_content(java_path))
            out.write("\n")

            out.write("expected:\n")
            if expected_path.exists():
                out.write(read_file_content(expected_path))
            else:
                out.write(f"[MISSING] Expected output file {expected_path.name} not found.\n")
            out.write("\n")

            out.write("current:\n")
            if current_path.exists():
                out.write(read_file_content(current_path))
            else:
                out.write(f"[MISSING] Current output file {current_path.name} not found.\n")
            out.write("\n")

            # Separator between test cases (except after the last written)
            # We don't know the last written easily, so just add separator always,
            # user can trim extra separator at end manually; or we can track.
            # Simpler: add separator for all except the very last test case overall?
            # But we're skipping, so we'll avoid separator inside loop and add later.
            # Better: write separator after each case except the last failing one.
            # We'll collect results in a list to know the last. For simplicity,
            # I'll just add a separator after each and you can ignore the final one.
            out.write("---\n\n")

        if failing_count == 0 and only_failing:
            out.write("All tests passed! No failing test cases to report.\n")

    print(f"Report written to {output_file}")
    print(f"Total test cases: {total_count}, failing/missing: {failing_count}")

def main():
    # Use command-line argument if provided, else current directory
    if len(sys.argv) > 1:
        folder = Path(sys.argv[1])
    else:
        folder = Path.cwd()

    if not folder.is_dir():
        print(f"Error: '{folder}' is not a valid directory.")
        sys.exit(1)

    output_file =  "java/compiler_failing_tests.txt"
    # Set only_failing=True (default) to skip passing tests
    process_folder(folder, output_file, only_failing=True)

if __name__ == "__main__":
    main()