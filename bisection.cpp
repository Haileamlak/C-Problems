#include <iostream>
#include <cmath>

using namespace std;

const double TLV = 0.00001;
double bisection(float, float);
double f(int);

int main()
{
    
    return 0;
}

double bisection(float a, float b)
{
    if (f(a) * f(b) >= 0)
        return b + 1;
    int c;

    do
    {
        c = (a + b) / 2;
        if (f(c) * f(b) < 0)
            a = c;
        else
            b = c;
    } while (abs(a - b) >= TLV);

    return c;
}

double f(int x)
{
    int res;
    return res;
}