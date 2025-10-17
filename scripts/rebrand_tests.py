#!/usr/bin/env python3
"""
Comprehensive script to rebrand all kuzu references to ryu in test directories.
Handles 2,358 occurrences across 67 test files including:
- C++ test files
- Test data files (.test, .csv)
- Test helper files
- C API test files
"""

import os
import re
from pathlib import Path

def find_and_replace_in_file(file_path, replacements):
    """Apply multiple find-and-replace operations to a file."""
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()

        original_content = content
        for pattern, replacement in replacements:
            if isinstance(pattern, str):
                content = content.replace(pattern, replacement)
            else:  # regex pattern
                content = pattern.sub(replacement, content)

        if content != original_content:
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(content)
            return True
        return False
    except Exception as e:
        print(f"⚠ Error processing {file_path}: {e}")
        return False

def get_common_replacements():
    """Get common replacements that apply to all test files."""
    return [
        # Namespace and includes
        ("namespace kuzu", "namespace ryu"),
        ("kuzu::", "ryu::"),
        ("using namespace kuzu", "using namespace ryu"),
        ('#include "kuzu.h"', '#include "ryu.h"'),
        ('#include "c_api/kuzu.h"', '#include "c_api/ryu.h"'),

        # CMake and constants
        ("KUZU_ROOT_DIRECTORY", "RYU_ROOT_DIRECTORY"),
        ("KUZU_PAGE_SIZE", "RYU_PAGE_SIZE"),
        ("KUZU_VECTOR_CAPACITY", "RYU_VECTOR_CAPACITY"),

        # C API functions and types
        (re.compile(r'\bkuzu_([a-z_]+)\b'), r'ryu_\1'),

        # Database/Connection class names (but be careful with test strings)
        ("KuzuDB", "RyuGraph"),
        ("Kuzu", "Ryu"),

        # Path references in test files
        ("/kuzu/", "/ryu/"),
        ("kuzu/", "ryu/"),

        # Simple lowercase (do last to avoid over-replacement)
        (re.compile(r'\bkuzu\b'), 'ryu'),
    ]

def process_file(file_path, file_type):
    """Process a single file based on its type."""
    replacements = get_common_replacements()

    # Add file-type specific replacements
    if file_type in ['cpp', 'h']:
        # C++ specific - already covered in common
        pass
    elif file_type == 'test':
        # Test files may have special syntax
        replacements.extend([
            ("# kuzu ", "# ryu "),
        ])
    elif file_type == 'csv':
        # CSV files - be conservative
        pass
    elif file_type == 'cmake':
        # CMakeLists specific
        replacements.extend([
            ("target_link_libraries", "target_link_libraries"),  # placeholder
        ])

    return find_and_replace_in_file(file_path, replacements)

def main():
    project_root = Path(__file__).parent.parent
    test_dir = project_root / "test"

    print(f"Project root: {project_root}")
    print(f"Processing test directory: {test_dir}\n")

    # File extensions to process
    extensions = {
        'cpp': ['cpp', 'cc'],
        'h': ['h', 'hpp'],
        'test': ['test'],
        'csv': ['csv'],
        'cmake': ['txt'],  # CMakeLists.txt
    }

    stats = {}
    total_files_processed = 0
    total_files_changed = 0

    # Process each file type
    for file_type, exts in extensions.items():
        files_changed = 0
        files_processed = 0

        for ext in exts:
            pattern = f"**/*.{ext}" if ext != 'txt' else "**/CMakeLists.txt"

            for file_path in test_dir.glob(pattern):
                if file_path.is_file():
                    files_processed += 1
                    total_files_processed += 1

                    if process_file(file_path, file_type):
                        files_changed += 1
                        total_files_changed += 1
                        print(f"✓ {file_path.relative_to(project_root)}")

        if files_changed > 0:
            stats[file_type] = f"{files_changed}/{files_processed} files"

    print("\n" + "="*60)
    print("SUMMARY")
    print("="*60)
    print(f"Total files processed: {total_files_processed}")
    print(f"Total files changed: {total_files_changed}")
    print("\nChanges by file type:")
    for file_type, stat in stats.items():
        print(f"  {file_type:10s}: {stat}")

    print("\n" + "="*60)
    print("Test rebranding complete!")
    print("="*60)

if __name__ == "__main__":
    main()
