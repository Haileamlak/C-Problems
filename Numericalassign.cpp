// C++ program for implementation of solving non-linear equations with different methods
// #include<bits/stdc++.h>
#include <iostream>
#include <cmath>
#define EPSILON 0.00001
#define MAX_ITER 1000000
#define f(x) 3 * pow(x, 3) + 5 * pow(x, 2) + 2;
using namespace std;

// An example function whose solution is pre-determined using
// Bisection Method.
// The function is 3x^3 - 5x^2  + 5
float g(float x);
void select();
float bisection(float, float);
float secant(float, float, float);
float newtonRaphson(float);
float falsePosition(float, float);
float FPI(float);
double func();
double derivFunc();

// Driver program to test above
int main()
{
    select();
    return 0;
}

// choose the method to solve
void select()
{
    char method;
    float a, b;

    cout << "choose by which method do you want to solve this equation\n";
    cout << "press\n    A- for Bisection method\n    B- for secant method\n    C- for newton's raphson method\n    D- for false position method\n    E- Fixed point iteration\n";
    cin >> method;
    switch (method)
    {
    case 'A':
    case 'a':
        bisection(a, b);
        break;
    case 'B':
    case 'b':
        secant(a, b, EPSILON);
    case 'C':
    case 'c':
        newtonRaphson(a);
        break;
    case 'D':
    case 'd':
        falsePosition(a, b);
    case 'E':
    case 'e':
        FPI(a);
    }
}

/* Write f(x) as x = g(x) and
   define g(x) here
     x=(-5x^2 - 2)/5 */
float g(float x)
{
    return cbrt((-5 * pow(x, 2) - 2) / 5);
}

double func(double x)
{
    return 3 * pow(x, 3) + 5 * pow(x, 2) + 2;
}

// Derivative of the above function which is 9x^2 - 10x
double derivFunc(double x)
{
    return 9 * pow(x, 2) + 10 * x;
}
// Function to find the root
float newtonRaphson(float x)
{
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x) / derivFunc(x);

        // x(i+1) = x(i) - f(x) / f'(x)
        x = x - h;
    }

    return x;
}
float bisection(float a, float b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n   please try again with different interval!";
        select();
    }

    double c = a;
    while (fabs(b - a) >= EPSILON)
    {
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (func(c) == 0.0)
        {
            break;
        }
        // Decide the side to repeat the steps
        else if (func(c) * func(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
   return c;
}

float secant(float x1, float x2, float E)
{
    float n = 0, xm, x0, c;
    if (func(x1) * func(x2) < 0)
    {
        do
        {
            // calculate the intermediate value
            x0 = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));

            // check if x0 is root of equation or not
            c = func(x1) * func(x0);

            // update the value of interval
            x1 = x2;
            x2 = x0;

            // update number of iteration
            n++;

            // if x0 is the root of equation then break the loop
            if (c == 0)
                break;
            xm = (x1 * func(x2) - x2 * func(x1)) / (func(x2) - func(x1));
        } while (fabs(xm - x0) >= E); // repeat the loop
                                      // until the convergence

        cout << "Root of the given equation=" << x0 << endl;
        cout << "No. of iterations = " << n << endl;
    }
    else
        cout << "Can not find a root in the given interval, please try again with different interval!";
    select();
}
void falsePosition(float a, float b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a; // Initialize result

    for (int i = 0; i < MAX_ITER; i++)
    {
        // Find the point that touches x axis
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        // Check if the above found point is root
        if (func(c) == 0)
            break;

        // Decide the side to repeat the steps
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}
float FPI(float x)
{
    int step;
    float x1;
    do
    {
        x1 = g(x);

        if (step > MAX_ITER)
        {
            cout << "maximum iteration reached and still Not Convergent!";
            exit(0);
        }
        x = x1;
        step = step + 1;

    } while (fabs(func(x1)) > EPSILON);

    return x1;
}