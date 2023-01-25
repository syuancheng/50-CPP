//
// Created by Siyuan Cheng on 2022/4/24.
//

#ifndef INC_50_CPP_TRIANGULAR_H
#define INC_50_CPP_TRIANGULAR_H

#include <vector>
#include <ostream>

class Triangular_iterator
{
public:
    Triangular_iterator(int index) : _index(index - 1){}
    bool operator==(const Triangular_iterator& ) const;
    bool operator!=(const Triangular_iterator&) const;
    int operator*()const;
    Triangular_iterator& operator++(); //前置
    const Triangular_iterator operator++(int); //后置

private:
    void check_integrity() const;
    int _index;
};

class Triangular{
public:
    friend class Triangular_iterator;

    Triangular(int len=1, int bp=1);
    Triangular(const Triangular&);
//    Triangular(int len, int beg_pos);

    int length() const {return _length;}
    int beg_pos() const {return _beg_pos;}
    int elem(int pos) const;

    static bool is_elem(int);
    static void gen_elements(int lenght);
    static void gen_elems_to_value(int value);
    static void display(int length, int beg_pos, std::ostream &os = cout);

    Triangular& copy(const Triangular &rhs);

    bool next(int &val) const;
    void next_reset() const { _next = 1;}

private:
    int _length;
    int _beg_pos;
    mutable int _next;

    static const int _max_elems = 1024;

    static std::vector<int> _elems;
};

bool Triangular::next(int &val) const {
    if (!_next){
        return false;
    }
    if (_next < _beg_pos + _length) {
        val = _elems[_next++];//data member _next is changed in a const function, so It will be failed during compile
        return true;
    }
    _next = 0;
    return false;
}

Triangular::Triangular(int len, int bp): _length(len>0 ? len : 1), _beg_pos(bp > 0? bp : 1) {
    _next = _beg_pos;
    int elem_cnt = _beg_pos + _length;
    if (_elems.size() < elem_cnt){
//        gen_el
    }
}

Triangular &Triangular::copy(const Triangular &rhs) {
    if (this != &rhs) {
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos - 1;
    }

    return *this;//this 指向调用copy方法的那个对象
}


int sum(const Triangular &trian){
    if (!trian.length()) {
        return 0;
    }
    int val, sum = 0;
    trian.next_reset();
    while(trian.next(val)) {
        sum+=val;
    }
    return sum;
}




bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const {
    return _index == rhs._index;
}

bool Triangular_iterator::operator!=(const Triangular_iterator &rhs) const {
    return !(*this == rhs);
}

void Triangular_iterator::check_integrity() const {
    if (_index >= Triangular::_max_elems){
        throw iterator_overflow();
    }
    if (_index >= Triangular::_elems.size()){
        Triangular::gen_elements(_index + 1);
    }
}

int Triangular_iterator::operator*() const {
    check_integrity();
    return Triangular::_elems[_index];
}

Triangular_iterator &Triangular_iterator::operator++() {
    ++_index;
    check_integrity();
    return *this;
}

const Triangular_iterator Triangular_iterator::operator++(int) {
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}


#endif //INC_50_CPP_TRIANGULAR_H
