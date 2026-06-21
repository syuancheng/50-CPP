#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <istream>
#include <ostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0; //类内初始值， 可以放在等号右边，也可使用花括号。 但是不能使用()
    double revenue = 0.0;
    //关于Sales_data对象的操作
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};

inline Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

inline double Sales_data::avg_price() const {
    if (units_sold)
    {
        return revenue/units_sold;
    } else {
        return 0;
    }
}

inline Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

//total.combine(trans), 当该函数被调用时，total的地址会被绑定到this上。而rhs绑定到trans上。

inline std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

inline std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}


inline Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


#endif
