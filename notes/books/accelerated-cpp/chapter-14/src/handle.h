#ifndef SYUAN_HANDLE_H
#define SYUAN_HANDLE_H

#include <memory>
#include <stdexcept>
#include <utility>

template <typename T>
class Handle {
public:
    Handle() = default;
    Handle(T* value) : p(value) {}

    Handle(const Handle& other)
        : p(other.p ? other.p->clone() : nullptr) {}

    Handle(Handle&&) noexcept = default;

    Handle& operator=(Handle other) noexcept {
        swap(other);
        return *this;
    }

    Handle& operator=(T* value) {
        p.reset(value);
        return *this;
    }

    explicit operator bool() const noexcept { return static_cast<bool>(p); }

    T& operator*() const {
        check_bound();
        return *p;
    }

    T* operator->() const {
        check_bound();
        return p.get();
    }

    void swap(Handle& other) noexcept { p.swap(other.p); }

private:
    void check_bound() const {
        if (!p) {
            throw std::runtime_error("unbound Handle");
        }
    }

    std::unique_ptr<T> p;
};

#endif // SYUAN_HANDLE_H
