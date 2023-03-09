#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void f(vector<T> &v1, vector<T> &v2)
{
    for (size_t i = 0; i < v1.size(); i++)
    {
        v1[i] += v2[i];
    }
}

template <typename T, typename U>
vector<T> &f2(vector<T> &vt, vector<U> &vu)
{

    for (size_t i = 0; i < vt.size(); i++)
    {
        vt[i] * vu[i];
    }
}

template <typename T1, typename T2>
class Pair
{
    T1 t1;
    T2 t2;
};

template <typename L>
struct Link
{
    L value;
    Link *prev;
    Link *succ;
    Link(const L &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}
};
template <typename T>
struct Number
{
    T num;
    Number<T>() : num(0)
    {
    }
    Number<T>(T n) : num(n)
    {
    }
    Number<T>(const Number &n)
    {
        num = n.num;
    }
    Number<T> &operator=(const Number &n)
    {
        num = n.num;
    }
    Number<T> operator+(const Number<T> &n1)
    {
        Number<T> res;
        res.num = num + n1.num;
        return res;
    }
    Number<T> operator-(const Number<T> &n1)
    {
        Number<T> res;
        res.num = num - n1.num;
        return res;
    }
    Number<T> operator*(const Number<T> &n1)
    {
        Number<T> res;
        res.num = num * n1.num;
        return res;
    }
    Number<T> operator/(const Number<T> &n1)
    {
        Number<T> res;
        res.num = num /n1.num;
        return res;
    }
    Number<T> operator%(const Number<T> &n1)
    {
        Number<T> res;
        res.num = num % n1.num;
        return res;
    }
};

template <typename T>
ostream &operator>>(ostream &is, Number<T> &n2)
{
    is >> n2.num;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const Number<T> n2)
{
    os << n2.num;
    return os;
}

int main()
{
    Number<int> in = 10;
    Number<int> dn = 4.5;
    cout << in / dn;
    return 0;
}