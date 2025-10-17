#!/usr/bin/env python3
"""
Comprehensive script to rebrand all kuzu references to ryu in the tools folder.
Handles 1197 occurrences across 136 files including:
- JavaScript/TypeScript files (WASM, Node.js)
- Python files (tests, source)
- C++ files (bindings)
- Rust files
- Java files
- Documentation files
- Build files
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
    """Get common replacements that apply to all file types."""
    return [
        # Package/module names
        ("kuzudb", "ryugraph"),
        ("KuzuDB", "RyuGraph"),

        # Class/type prefixes
        ("KuzuMap", "RyuMap"),
        ("KuzuList", "RyuList"),
        ("KuzuStruct", "RyuStruct"),

        # Basic variations (order matters - do compound words before simple words)
        ("Kuzu", "Ryu"),
        ("kuzu", "ryu"),
        ("KUZU", "RYU"),
    ]

def process_file(file_path, file_type):
    """Process a single file based on its type."""
    replacements = get_common_replacements()

    # Add file-type specific replacements
    if file_type in ['js', 'ts', 'mjs']:
        # JavaScript/TypeScript specific
        replacements.extend([
            (re.compile(r"'kuzu'"), "'ryu'"),
            (re.compile(r'"kuzu"'), '"ryu"'),
            (re.compile(r'const kuzu ='), 'const ryu ='),
            (re.compile(r'import kuzu from'), 'import ryu from'),
            (re.compile(r'require\("kuzu"\)'), 'require("ryu")'),
        ])
    elif file_type == 'py':
        # Python specific
        replacements.extend([
            (re.compile(r'import kuzu'), 'import ryu'),
            (re.compile(r'from kuzu import'), 'from ryu import'),
            (re.compile(r"'kuzu'"), "'ryu'"),
            (re.compile(r'"kuzu"'), '"ryu"'),
        ])
    elif file_type in ['cpp', 'h']:
        # C++ specific
        replacements.extend([
            ('#include "kuzu.h"', '#include "ryu.h"'),
            ('#include "kuzu_fwd.h"', '#include "ryu_fwd.h"'),
            ('kuzu::', 'ryu::'),
            ('namespace kuzu', 'namespace ryu'),
        ])
    elif file_type == 'rs':
        # Rust specific
        replacements.extend([
            (re.compile(r'extern crate kuzu;'), 'extern crate ryu;'),
            (re.compile(r'use kuzu::'), 'use ryu::'),
        ])
    elif file_type == 'java':
        # Java specific
        replacements.extend([
            ('com.kuzudb', 'com.ryugraph'),
            ('import com.kuzudb', 'import com.ryugraph'),
        ])

    return find_and_replace_in_file(file_path, replacements)

def main():
    project_root = Path(__file__).parent.parent
    tools_dir = project_root / "tools"

    print(f"Project root: {project_root}")
    print(f"Processing tools directory: {tools_dir}\n")

    # File extensions to process
    extensions = {
        'js': ['js', 'mjs'],
        'ts': ['ts', 'd.ts'],
        'py': ['py'],
        'cpp': ['cpp', 'cc'],
        'h': ['h', 'hpp'],
        'rs': ['rs'],
        'java': ['java'],
        'md': ['md'],
        'toml': ['toml'],
        'json': ['json'],
        'lock': ['lock'],
        'gradle': ['gradle'],
        'sh': ['sh'],
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

            for file_path in tools_dir.glob(pattern):
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
    print("Rebranding complete!")
    print("="*60)

if __name__ == "__main__":
    main()
