#include "A.h"

A::A()
{
    a = 0;
}

A A::operator+(const A& b)
{
    A c = *this;
    c.a += b.a;
    return c;
}

A A::operator-(const A& b)
{
    A c = *this;
    c.a -= b.a;
    return c;
}

A A::operator*(const A& b)
{
    A c = *this;
    c.a *= b.a;
    return c;
}

A A::operator/(const A& b)
{
    A c = *this;
    c.a /= b.a;
    return c;
}

A& A::operator=(const A& b)
{
    a = b.a; 
    return *this;
}

A& A::operator+=(const A& b)
{
    a += b.a;
    return *this;
}

A& A::operator-=(const A& b)
{
    a -= b.a;
    return *this;
}

A& A::operator*=(const A& b)
{
    a *= b.a;
    return *this;
}

A& A::operator/=(const A& b)
{
    a /= b.a;
    return *this;
}

bool A::operator<(const A& b)
{
    return a < b.a;
}

bool A::operator>(const A& b)
{
    return a > b.a;
}

ostream& operator<<(ostream& os, const A& obj)
{
    os << obj.a;
    return os;
}

