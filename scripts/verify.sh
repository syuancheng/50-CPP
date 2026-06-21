#!/usr/bin/env bash

set -euo pipefail

root_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
build_root=${TMPDIR:-/tmp}/50-cpp-verify

cmake -S "$root_dir" -B "$build_root/root" \
  -DCPP_NOTES_WARNINGS_AS_ERRORS=ON \
  -DCMAKE_BUILD_TYPE=Debug
cmake --build "$build_root/root" --parallel
ctest --test-dir "$build_root/root" --output-on-failure

projects=(
  notes/books/accelerated-cpp/chapter-04
  notes/books/accelerated-cpp/chapter-05
  notes/books/accelerated-cpp/chapter-09
  notes/books/accelerated-cpp/chapter-10
  notes/books/accelerated-cpp/chapter-13
  notes/books/accelerated-cpp/chapter-14
  notes/language-basics/classes
  notes/language-basics/inheritance
  notes/language-basics/polymorphism
  notes/language-basics/types
  notes/language-basics/polymorphism-shapes
  notes/language-basics/sorting
  notes/books/essential-cpp/chapter-04
  examples/build-system/cmake/basic/01-hello-cmake
  examples/build-system/cmake/basic/02-hello-headers
  examples/build-system/cmake/basic/03-static-library
  examples/build-system/cmake/basic/04-shared-library
  examples/build-system/cmake/basic/05-build-type
  examples/build-system/cmake/sub-projects/01-basic
)

for project in "${projects[@]}"; do
  build_name=${project//\//_}
  cmake -S "$root_dir/$project" -B "$build_root/$build_name" \
    -DCMAKE_BUILD_TYPE=Debug
  cmake --build "$build_root/$build_name" --parallel
done

ctest --test-dir "$build_root/notes_books_accelerated-cpp_chapter-05" --output-on-failure

echo "All dependency-free examples built and tests passed."
