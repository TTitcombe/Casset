#!/bin/bash -ex

CLANG_FORMAT=clang-format-5.0
$CLANG_FORMAT --version

files="$(git diff --name-only --diff-filter=ACMRTUXB $TRAVIS_COMMIT_RANGE | grep '^src/[^.]*[.]\(cpp\|h\)$' || true)"

set +x

for f in files; do
   d=$(diff -u "$f" <($CLANG_FORMAT "$f") || true)
   if ! [ -z "$d" ]; then
       echo "Clang-format results for file $f:"
       echo "$d"
       fail=1
   fi
done

set -x

if [ "$fail" = 1 ]; then
   exit 1
fi