#ifndef SYUAN_HANDLE_H
#define SYUAN_HANDLE_H

#include <iostream>

template <typename T> class Handle
{
private:
    T* p;
public:
    Handle():p(0) {}
    Handle(const Handle& s):p(0) {
        if (s.p)
        {
            p = s.p->clone();
        }
    }
    Handle& operator=(const Handle&);
    ~Handle() {delete p;}
    Handle(T* t):p(t) {}
    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

};

#endif // SYUAN_HANDLE_H
