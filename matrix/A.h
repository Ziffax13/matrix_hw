#include <iostream>;
using namespace std;

class A
{
    int a;
public:
    A();
    A(int);

    A operator+(const A&);

    A operator-(const A&);

    A operator*(const A&);

    A operator/(const A&);

    A& operator=(const A&);
    A& operator+=(const A&);
    A& operator-=(const A&);
    A& operator*=(const A&);
    A& operator/=(const A&);

    bool operator<(const A&);

    bool operator>(const A&);

    friend ostream& operator<<(ostream&, const A&);
};

