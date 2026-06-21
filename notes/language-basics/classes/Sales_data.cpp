#include "Sales_data.h"

#include <cassert>
#include <sstream>

int main() {
    std::istringstream input("0-201 2 30.0 0-201 3 25.0");
    Sales_data first;
    Sales_data second;
    read(input, first);
    read(input, second);

    const Sales_data total = add(first, second);
    assert(total.isbn() == "0-201");
    assert(total.units_sold == 5);
    assert(total.revenue == 135.0);
    assert(total.avg_price() == 27.0);
}
