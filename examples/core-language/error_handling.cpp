#include <cassert>
#include <charconv>
#include <optional>
#include <string_view>

std::optional<int> parse_int(std::string_view text) {
    int value = 0;
    const char* begin = text.data();
    const char* end = begin + text.size();
    const auto [position, error] = std::from_chars(begin, end, value);

    if (error != std::errc{} || position != end) {
        return std::nullopt;
    }
    return value;
}

int main() {
    const auto valid = parse_int("42");
    assert(valid && *valid == 42);
    assert(!parse_int("42px"));
    assert(!parse_int("not-a-number"));
}
