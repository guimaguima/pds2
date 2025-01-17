#ifndef HEAPINT_H
#define HEAPINT_H

#include <iostream>

using namespace std;

class HeapInt
{
private:
    int *_val;

public:
    HeapInt();
    HeapInt(int);
    HeapInt(const HeapInt &);
    ~HeapInt();
    void operator=(const HeapInt &);
    void operator=(const int &);
    HeapInt operator+(HeapInt &) const;
    HeapInt operator-(HeapInt &) const;
    bool operator==(HeapInt &) const;
    friend std::istream &operator>>(std::istream &, HeapInt &);
    friend std::ostream &operator<<(std::ostream &, const HeapInt &);
};

#endif
