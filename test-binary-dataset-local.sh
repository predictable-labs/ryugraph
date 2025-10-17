#!/bin/bash
# Test binary dataset generation locally
# This mimics what GitHub Actions does for the generate-binary-datasets job

set -e

echo "Testing binary dataset generation locally..."
echo ""

# Check if we need to build first
if [ ! -f "build/release/tools/shell/ryu" ]; then
    echo "Release build not found. Building first..."
    echo ""
    make release
    echo ""
fi

echo "=== Testing binary-demo dataset generation ==="
bash scripts/generate_binary_demo.sh

if [ -d "dataset/binary-demo" ]; then
    echo "✅ binary-demo dataset generated successfully"
    echo "   Location: dataset/binary-demo"
    ls -lh dataset/binary-demo/
else
    echo "❌ binary-demo dataset generation failed"
    exit 1
fi

echo ""
echo "=== Testing tinysnb dataset generation ==="
bash scripts/generate_binary_tinysnb.sh

if [ -d "tinysnb" ]; then
    echo "✅ tinysnb dataset generated successfully"
    echo "   Location: tinysnb"
    ls -lh tinysnb/
    rm -rf tinysnb  # Clean up
else
    echo "❌ tinysnb dataset generation failed"
    exit 1
fi

echo ""
echo "✅ All binary dataset generation tests passed!"
echo ""
echo "Note: S3 upload steps are skipped in local testing"
