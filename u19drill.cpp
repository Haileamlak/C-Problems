#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct S
{
    S(const T &t) : val(t)
    {
    }
    T &get();
    const T &get() const;
    T &set(const T &newval);
    T &operator=(const T &);

private:
    T val;
};

template <typename T>
T &S<T>::get()
{
    return val;
}

template <typename T>
const T &S<T>::get() const
{
    return val;
}
template <typename T>
T &S<T>::set(const T &newval)
{
    val = newval;
}
template <typename T>
T &S<T>::operator=(const T &tt)
{
    val = tt;
}

template <typename T>
void read_val(T &v)
{
    cin >> v;
}

template <typename T>
ostream &operator<<(ostream &os, T &s)
{
    os << s.val;
    return os;
}

template <typename T>
istream &operator>>(istream &is, S<T> &s)
{
    is >> s.get();
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &t)
{
    os << "{";
    for (size_t i = 0; i < t.size(); i++)
    {
        os << " " << t[i];
        if (i == t.size() - 1)
            os << " }";
        else
            os << ',';
    }
    return os;
}

int main()
{
    S<int> si(4);
    read_val<S<int>>(si);
    S<char> sc('A');
    read_val<S<char>>(sc);
    S<double> sd(4.5);
    read_val<S<double>>(sd);
    S<string> ss("sstring");
    read_val<S<string>>(ss);
    vector<int> vi{1, 2, 3, 4, 5};
    S<vector<int>> svi(vi);
    // read_val<S<vector<int>>>(ss);

    cout << si << endl;
    cout << sc << endl;
    cout << sd << endl;
    cout << ss << endl;
    for (size_t i = 0; i < svi.get().size(); i++)
    {
        /* code */
        cout << svi.get()[i] << endl;
    }
    
    return 0;
}