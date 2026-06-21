#ifndef INC_50_CPP_TRIANGULAR_H
#define INC_50_CPP_TRIANGULAR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class iterator_overflow : public std::out_of_range {
public:
    iterator_overflow() : std::out_of_range("triangular iterator overflow") {}
};

class Triangular_iterator {
public:
    explicit Triangular_iterator(int index) : index_(index - 1) {}
    bool operator==(const Triangular_iterator& rhs) const { return index_ == rhs.index_; }
    bool operator!=(const Triangular_iterator& rhs) const { return !(*this == rhs); }
    int operator*() const;
    Triangular_iterator& operator++();
    Triangular_iterator operator++(int);

private:
    void check_integrity() const;
    int index_;
};

class Triangular {
public:
    friend class Triangular_iterator;

    explicit Triangular(int length = 1, int begin_position = 1)
        : length_(length > 0 ? length : 1),
          begin_position_(begin_position > 0 ? begin_position : 1),
          next_(begin_position_ - 1) {
        const int required = begin_position_ - 1 + length_;
        if (required > max_elements_) {
            throw std::length_error("triangular sequence is too large");
        }
        gen_elements(required);
    }

    int length() const noexcept { return length_; }
    int beg_pos() const noexcept { return begin_position_; }

    int elem(int position) const {
        if (position < 1 || position > length_) {
            throw std::out_of_range("position outside triangular range");
        }
        return elements_[begin_position_ + position - 2];
    }

    static bool is_elem(int value) {
        gen_elems_to_value(value);
        return std::binary_search(elements_.begin(), elements_.end(), value);
    }

    static void gen_elements(int length) {
        if (length < 0 || length > max_elements_) {
            throw std::length_error("triangular sequence is too large");
        }
        while (static_cast<int>(elements_.size()) < length) {
            const int n = static_cast<int>(elements_.size()) + 1;
            elements_.push_back(n * (n + 1) / 2);
        }
    }

    static void gen_elems_to_value(int value) {
        while ((elements_.empty() || elements_.back() < value) &&
               static_cast<int>(elements_.size()) < max_elements_) {
            gen_elements(static_cast<int>(elements_.size()) + 1);
        }
    }

    static void display(int length, int begin_position,
                        std::ostream& output = std::cout) {
        const Triangular sequence(length, begin_position);
        for (int position = 1; position <= sequence.length(); ++position) {
            output << sequence.elem(position)
                   << (position == sequence.length() ? '\n' : ' ');
        }
    }

    Triangular& copy(const Triangular& rhs) {
        if (this != &rhs) {
            length_ = rhs.length_;
            begin_position_ = rhs.begin_position_;
            next_ = begin_position_ - 1;
        }
        return *this;
    }

    bool next(int& value) const {
        const int end = begin_position_ - 1 + length_;
        if (next_ >= end) {
            return false;
        }
        value = elements_[next_++];
        return true;
    }

    void next_reset() const noexcept { next_ = begin_position_ - 1; }

private:
    int length_;
    int begin_position_;
    mutable int next_;

    static constexpr int max_elements_ = 1024;
    inline static std::vector<int> elements_;
};

inline int sum(const Triangular& sequence) {
    int value = 0;
    int result = 0;
    sequence.next_reset();
    while (sequence.next(value)) {
        result += value;
    }
    return result;
}

inline void Triangular_iterator::check_integrity() const {
    if (index_ < 0 || index_ >= Triangular::max_elements_) {
        throw iterator_overflow();
    }
    Triangular::gen_elements(index_ + 1);
}

inline int Triangular_iterator::operator*() const {
    check_integrity();
    return Triangular::elements_[index_];
}

inline Triangular_iterator& Triangular_iterator::operator++() {
    ++index_;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int) {
    Triangular_iterator previous = *this;
    ++(*this);
    return previous;
}

#endif
