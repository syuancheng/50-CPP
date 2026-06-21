#include "include/str_proc.h"

#include <cassert>
#include <string>
#include <vector>

int main() {
    assert(split("").empty());
    assert(split("   ").empty());
    assert((split("C++ values and RAII") ==
            std::vector<std::string>{"C++", "values", "and", "RAII"}));
}
