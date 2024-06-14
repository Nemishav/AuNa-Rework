#!/bin/bash

# License text with placeholders
LICENSE_CPP_HPP="// Copyright (c) 2024 Harun Teper
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.\n"

LICENSE_PY="\
# Copyright (c) 2024 Harun Teper
#
# Use of this source code is governed by an MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT.
"

# Function to add license text to files, if not already present
add_license_to_files() {
    local file_pattern="$1"
    local license_text="$2"

    # Find all files matching the pattern and iterate through them
    find . -type f -name "$file_pattern" | while IFS= read -r file; do
        # Check if file exists and is readable
        if [ -f "$file" ] && [ -r "$file" ]; then
            # Check if the license text is already present
            echo "Checking license in: $file"
            if grep -xq "$license_text" "$file"; then
                echo "License already present in: $file"
            else
                # Add license text to the beginning of the file
                temp_file=$(mktemp)
                echo -e "$license_text" | cat - "$file" > "$temp_file" && mv "$temp_file" "$file"
                echo "Added license to: $file"
            fi
        else
            echo "Error: Cannot read file or file does not exist: $file"
        fi
    done
}

# Add license text to .hpp and .cpp files
add_license_to_files "*.hpp" "$LICENSE_CPP_HPP" "//"
add_license_to_files "*.cpp" "$LICENSE_CPP_HPP" "//"

# Add license text to .py files
add_license_to_files "*.py" "$LICENSE_PY" "#"

echo "License addition completed."
