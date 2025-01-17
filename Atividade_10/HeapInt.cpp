#include <iostream>
#include "HeapInt.hpp"

HeapInt::HeapInt() : _val(new int(0)) {}

HeapInt::HeapInt(int valor) : _val(new int(valor)) {}

HeapInt::HeapInt(const HeapInt &outro) : _val(new int(*outro._val)) {}

HeapInt::~HeapInt()
{
    delete this->_val;
}

void HeapInt::operator=(const HeapInt &outro)
{
    *this->_val = *outro._val;
}

void HeapInt::operator=(const int &valor)
{
    *this->_val = valor;
}

HeapInt HeapInt::operator+(HeapInt &outro) const
{
    int temp = *this->_val + *outro._val;
    return HeapInt(temp);
}

HeapInt HeapInt::operator-(HeapInt &outro) const
{
    int temp = *this->_val - *outro._val;
    return HeapInt(temp);
}

bool HeapInt::operator==(HeapInt &outro) const
{
    if (*this->_val == *outro._val)
        return true;
    return false;
}

std::istream &operator>>(std::istream &in, HeapInt &obj)
{
    in >> *obj._val;
    return in;
}

std::ostream &operator<<(std::ostream &out, const HeapInt &obj)
{
    out << *obj._val;
    return out;
}