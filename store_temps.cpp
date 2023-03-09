
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <regex>
#include <random>
#include <stdexcept>
using namespace std;
float F_to_C(float f);
struct Reading
{
    int day;
    int hour;
    double temp;
};
istream &operator>>(istream &is, Reading &x)
{
    char ch1, ch2, ch3, ch4, ch;
    int a, b;
    double c;
    is >> ch1 >> a >> ch2 >> b >> ch3 >> ch >> c >> ch4;
    if (ch == 'f')
        c = F_to_C(c);
    else if (ch == 'c')
        ;
    else
        exit(2);
    x.day = a;
    x.hour = b;
    x.temp = c;
    return is;
}
ostream &operator<<(ostream &os, Reading &x)
{
    return os << "(" << x.day << ", " << x.hour << ", " << x.temp << ")";
}

class Roman_int {
public:
    int value;
    int as_int() { return value; }
};
istream &operator>>(istream &is, Roman_int &x)
{
    char y;
    is >> y;
    x.value = y;
    return is;
}
int main()
{
    int sum = 0;
    double mean = 0;
    fstream fst{"mydata.txt"};
    cout << "yes\n";
    // fst.open("mydata.txt", ios::in);
    vector<Reading> temps;
    Reading i;
    for (; fst >> i;)
    {
        temps.push_back(i);
        sum += i.temp;
    }
    mean = ceil(sum / temps.size());
    cout << setprecision(3) << mean << endl;
    for (Reading &x : temps)
        cout << x << "\n";
    // sort(temps.begin(), temps.end());
    for (Reading &x : temps)
        cout << x << "\n";
    return 0;
}

float F_to_C(float f) // converts kelvin to celsius
{
    //     if (f < 32 || f > 212)
    //     {
    //         cerr << "error : temperature expected";
    //         exit(1);
    //     }
    float c = round((5.0 / 9.0) * (f - 32));
    return c;
}




int Roman_int(char x)
{

}