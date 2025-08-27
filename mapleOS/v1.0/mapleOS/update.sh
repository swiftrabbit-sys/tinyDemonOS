#!/bin/bash
#!/bin/bash

# MapleOS Update Script
# Compiles all .cpp files into .o and links if main() exists

set -e

echo "=== MapleOS Update Utility ==="
echo "[INFO] Scanning for .cpp files..."

FILES=$(find . -type f -name "*.cpp")

if [ -z "$FILES" ]; then
    echo "[ERROR] No .cpp files found."
    exit 1
fi

for file in $FILES; do
    base=$(basename "$file" .cpp)
    dir=$(dirname "$file")
    obj="$dir/$base.o"
    exe="$dir/$base"

    echo ""
    echo "[BUILD] Processing $file"
    echo "Compiling: $file -> $obj"
    g++ -c "$file" -o "$obj"

    if grep -q "int main" "$file"; then
        echo "Linking: $obj -> $exe"
        g++ "$obj" -o "$exe"
    else
        echo "[INFO] No main() in $file, skipping link."
    fi
done

echo ""
echo "[SUCCESS] All compilation and linking steps completed."

