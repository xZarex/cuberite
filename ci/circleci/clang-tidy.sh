#!/bin/sh

set -e

CONFIG="Checks: '-*,readability-identifier-naming'
CheckOptions:
- key:             readability-identifier-naming.PrivateMemberPrefix
  value:           'm_'
- key:             readability-identifier-naming.ClassConstantCase
  value:           aNy_CasE
# an empty *Prefix needs a *Case to work
- key:             readability-identifier-naming.ClassConstantPrefix
  value:           ''
#- key:             readability-identifier-naming.PrivateMemberCase
#  value:           CamelCase
#- key:             readability-identifier-naming.FunctionCase
#  value:           CamelCase
#- key:             readability-identifier-naming.EnumCase
#  value:           camelBack
WarningsAsErrors: '*'
HeaderFilterRegex: '/cuberite/src/\.?[^\.]'"

FIXES_FILE="tidy-fixes.yaml"
REGEX="/cuberite/src/\.?[^\.]"
ARGS="-config $CONFIG -header-filter $REGEX -quiet -export-fixes $FIXES_FILE "$@" $REGEX"

mkdir -p tidy-build
cd tidy-build
cmake --target Cuberite -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

if run-clang-tidy.py $ARGS; then
	echo "clang-tidy: No violations found"
else
	echo "clang-tidy: Found violations"
	exit 1
fi
