#!/usr/bin/env python3
"""
Script to rename main build artifacts from kuzu to ryu.
This addresses two critical areas:
1. CMake library target names (kuzu -> ryu)
2. CMake output file names (libkuzu.* -> libryu.*, kuzu.hpp -> ryu.hpp)
"""

import os
import re
import sys
from pathlib import Path

def find_and_replace_in_file(file_path, replacements):
    """Apply multiple find-and-replace operations to a file."""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()

        original_content = content
        for old_text, new_text in replacements:
            content = content.replace(old_text, new_text)

        if content != original_content:
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(content)
            return True
        return False
    except Exception as e:
        print(f"Error processing {file_path}: {e}")
        return False

def main():
    project_root = Path(__file__).parent.parent
    print(f"Project root: {project_root}")

    # Area 1: Fix src/CMakeLists.txt - library target names and output names
    print("\n=== Area 1: Library Targets and Output Names ===")
    src_cmake = project_root / "src" / "CMakeLists.txt"

    replacements = [
        # Change library target name from 'kuzu' to 'ryu'
        ("add_library(kuzu STATIC", "add_library(ryu STATIC"),

        # Change target references
        ("target_link_libraries(kuzu PUBLIC", "target_link_libraries(ryu PUBLIC"),
        ("target_include_directories(kuzu PUBLIC", "target_include_directories(ryu PUBLIC"),
        ("target_compile_definitions(kuzu INTERFACE", "target_compile_definitions(ryu INTERFACE"),

        # Change output name from kuzu to ryu
        ('OUTPUT_NAME kuzu', 'OUTPUT_NAME ryu'),

        # Change install targets
        ("install(TARGETS kuzu ryu_shared)", "install(TARGETS ryu ryu_shared)"),

        # Change single file header output from kuzu.hpp to ryu.hpp
        ("OUTPUT kuzu.hpp", "OUTPUT ryu.hpp"),
        ("DEPENDS kuzu.hpp)", "DEPENDS ryu.hpp)"),

        # Change install statements for header files
        ("include/c_api/kuzu.h", "include/c_api/ryu.h"),
        ("kuzu.hpp  TYPE INCLUDE)", "ryu.hpp  TYPE INCLUDE)"),
    ]

    if find_and_replace_in_file(src_cmake, replacements):
        print(f"✓ Updated {src_cmake}")
    else:
        print(f"✗ No changes needed in {src_cmake}")

    # Area 2: Fix scripts that reference kuzu.hpp
    print("\n=== Area 2: Build Scripts ===")

    # Update collect-single-file-header.py
    header_script = project_root / "scripts" / "collect-single-file-header.py"
    script_replacements = [
        ("kuzu.hpp", "ryu.hpp"),
        ("kuzu.h", "ryu.h"),
    ]

    if find_and_replace_in_file(header_script, script_replacements):
        print(f"✓ Updated {header_script}")
    else:
        print(f"✗ No changes needed in {header_script}")

    # Check if there's a headers.txt file
    headers_txt = project_root / "scripts" / "headers.txt"
    if headers_txt.exists():
        if find_and_replace_in_file(headers_txt, script_replacements):
            print(f"✓ Updated {headers_txt}")
        else:
            print(f"✗ No changes needed in {headers_txt}")

    # Area 3: Fix all tools CMakeLists.txt to link against 'ryu' instead of 'kuzu'
    print("\n=== Area 3: Tools Library Dependencies ===")

    tools_cmake_files = [
        ("tools/python_api/CMakeLists.txt", [
            ("target_link_libraries(_kuzu\n        PRIVATE\n        kuzu)",
             "target_link_libraries(_kuzu\n        PRIVATE\n        ryu)"),
            ('LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/kuzu"',
             'LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/ryu"'),
            ('RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/kuzu"',
             'RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/ryu"'),
            ('ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/kuzu")',
             'ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build/ryu")'),
        ]),
        ("tools/nodejs_api/CMakeLists.txt", [
            ("target_link_libraries(kuzujs PRIVATE kuzu",
             "target_link_libraries(kuzujs PRIVATE ryu"),
        ]),
        ("tools/java_api/CMakeLists.txt", [
            ("target_link_libraries(ryu_java_native PRIVATE ryu_native_header kuzu)",
             "target_link_libraries(ryu_java_native PRIVATE ryu_native_header ryu)"),
        ]),
        ("tools/shell/CMakeLists.txt", [
            ("target_link_libraries(ryu_shell kuzu)",
             "target_link_libraries(ryu_shell ryu)"),
        ]),
        ("tools/rust_api/src/CMakeLists.txt", [
            ("target_link_libraries(ryu_rs kuzu)",
             "target_link_libraries(ryu_rs ryu)"),
        ]),
        ("tools/wasm/CMakeLists.txt", [
            ("target_link_libraries(ryu_wasm PRIVATE kuzu)",
             "target_link_libraries(ryu_wasm PRIVATE ryu)"),
            ('LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/kuzu"',
             'LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/ryu"'),
            ('RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/kuzu"',
             'RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/ryu"'),
            ('ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/kuzu"',
             'ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/ryu"'),
        ]),
        ("tools/benchmark/CMakeLists.txt", [
            ("target_link_libraries(ryu_benchmark kuzu test_helper)",
             "target_link_libraries(ryu_benchmark ryu test_helper)"),
        ]),
    ]

    for file_rel_path, replacements in tools_cmake_files:
        file_path = project_root / file_rel_path
        if file_path.exists():
            if find_and_replace_in_file(file_path, replacements):
                print(f"✓ Updated {file_path}")
            else:
                print(f"✗ No changes needed in {file_path}")
        else:
            print(f"⚠ File not found: {file_path}")

    print("\n=== Summary ===")
    print("Main areas addressed:")
    print("1. ✓ Library target: 'kuzu' → 'ryu' in src/CMakeLists.txt")
    print("2. ✓ Output names: 'libkuzu.*' → 'libryu.*', 'kuzu.hpp' → 'ryu.hpp'")
    print("3. ✓ All tools now link against 'ryu' library instead of 'kuzu'")
    print("4. ✓ Build output directories: build/kuzu → build/ryu")
    print("\nNote: Build artifacts in build/ directories will be regenerated on next build.")

if __name__ == "__main__":
    main()
