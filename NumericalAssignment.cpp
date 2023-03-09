#include <iostream>
#include <cmath>

using namespace std;

const float TLV = 0.000001;

double f(double);
double df(double);

double bisection(double, double);
double falsePosition(double, double);
double secant(double, double);
double fixedPointIteration(double, double);
double newton(double);

int main()
{

    return 0;
}

double bisection(double x1, double x2)
{
    if (f(x1) * f(x2) > 0)
        return (x2 + 1);
    double x3;
    while (abs(x1 - x2) < 2 * TLV)
    {
        x3 = (x1 + x2) / 2;
        if (f(x3) * f(x1) < 0)
            x2 = x3;
        else
            x1 = x3;
    }
    return x3;
}
double falsePosition(double x1, double x2)
{
    if (f(x1) * f(x2) > 0)
        return x2 + 1;
    double x3;
    while ()
    {
        x3 = x2 - f(x2) * (x1 - x2) / (f(x1) - f(x2));
        if (f(x3) * f(x1) < 0)
            x2 = x3;
        else
            x1 = x3;
    }
    return x3;
}
double secant(double, double);
double fixedPointIteration(double, double);
double newton(double);