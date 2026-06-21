#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> values{7, 2, 5, 2, 9, 4};

    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());

    const auto even_count = std::count_if(
        values.begin(), values.end(), [](int value) { return value % 2 == 0; });
    const int sum = std::accumulate(values.begin(), values.end(), 0);

    assert((values == std::vector<int>{2, 4, 5, 7, 9}));
    assert(even_count == 2);
    assert(sum == 27);
}
