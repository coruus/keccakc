#!/usr/bin/env sh
name="$(/usr/bin/env echo -n "$1" | sed -e "s/\(\..*\)//")"
macros=${name}.macros
out="$(/usr/bin/env echo -n "$1" | sed -e "s/\(\.[^.]\)\(.*\)/\1/")"
format="clang-format -i -style=file"
cpp="cpp -std=c11 -CC"
echo "applying ${macros} to ${1}; output to ${out}"
# Apply CPP; -P suppresses line numbers.
$cpp -imacros "${macros}" "${1}" > "${out}"
# Format the resulting file.
${format} "${out}"
# Delete leading blank lines.
sed -i -n -e '/./,$!d' "${out}"
