#!/usr/bin/env sh
header_name=$(/usr/bin/env echo -n "$1" | tr '/.-' '___' | tr '[:lower:]' '[:upper:]')
echo "created ${header_name} at $1"
cat >> "$1" <<HEADER_TEMPLATE
#ifndef ${header_name}
#define ${header_name}

#endif  // ${header_name}
HEADER_TEMPLATE
