//
// Created by Siyuan Cheng on 2022/4/24.
//

#ifndef CHAPTER4_LESS_THAN_H
#define CHAPTER4_LESS_THAN_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class LessThan {
public:
    LessThan(int val) : _val(val) {}
    int comp_val() const {return _val;}
    void comp_val(int nval){_val = nval;}

    bool operator() (int _value) const;

private:
    int _val;
};

inline bool LessThan::operator()(int value) const { return value < _val;}

int count_less_than(const std::vector<int> &vec, int comp)
{
    LessThan lt(comp);

    int count = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (lt(lt(vec[i]))){
            ++count;
        }
    }
    return count;
}

void print_less_than( const std::vector<int> &vec,
                      int comp, std::ostream &os = std::cout )
{
    LessThan lt( comp );

    std::vector<int>::const_iterator iter = vec.begin();
    std::vector<int>::const_iterator it_end = vec.end();

    os << "elements less than " << lt.comp_val() << std::endl;
    while (( iter = find_if( iter, it_end, lt )) != it_end )
    {
        os << *iter << ' ';
        ++iter;
    }
}

#endif //CHAPTER4_LESS_THAN_H
