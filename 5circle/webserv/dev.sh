#!/bin/sh

set -e

cd "$(dirname "$0")"

find src -name "*.cpp" | while IFS= read -r path; do
  clang -xc++ -Wall -Wextra -Werror -std=c++98 -pedantic -Iheader -MJ "$path.part.json" -c "$path" ||:
done

(echo '[' && find . -name "*.part.json" -exec cat {} \+ && echo ']') > compile_commands.json
find . \( -name "*.part.json" -o -name "*.o" \) -delete
