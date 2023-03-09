#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Equation
{
    int coef;
    vector<Function *> funcs;
    Equation *power;
    string ops;
};
class Function
{
public:
    int coef;
    Function *poww;
    virtual double f(int x);
    int getCoef() { return coef; }
};

class constant : Function
{
public:
    constant(string f)
    {
        coef = stoi(f);
    }
    double f(int x)
    {
        return coef;
    }
};

class power : Function
{
public:
    int p;
    power(string f)
    {
        p = stoi(f);
    }
    double f(int x)
    {
        return getCoef() * pow(pow(x, p), poww->f(x));
    }
};

class sine : Function
{
public:
    // int s;
    sine(string f)
    {
    }
    double f(int x)
    {
        return getCoef() * pow(sin(x), poww->f(x));
    }
};
class Log : Function
{
public:
    // int g;
    Log() {}
    double f(int x)
    {
        return getCoef() * pow(log10(x), poww->f(x));
    }
};
class Exp : Function
{
public:
    int b;
    Exp(string f) { b = stoi(f); }
    double f(int x) { return getCoef() * pow(pow(b, x), poww->f(x)); }
};

class functions : Function
{
public:
    vector<Function *> funs;
    string ops;
    functions(string f)
    {
        string coff = "";
        size_t i = 0;
        for (; isalnum(f[i]); i++)
        {
            coff += f[i];
        }
        f.erase(0, i);
        if (i)
            coff = "1";
        if (f[i] == "(")
    }
    double f(int x)
    {
        vector<double> funRes;
        for (size_t i = 0; i < funs.size(); i++)
        {
            funRes.push_back(funs[i]->f(x));
        }

        for (size_t i = 0; i < ops.length(); i++)
        {
            if (ops[i] == '*')
            {
                funRes[i] = funRes[i] * funRes[i + 1];
                funRes.erase(funRes.begin() + i + 1);
                ops.erase(ops.begin() + i);
                i--;
            }
            else if (ops[i] == '/')
            {
                funRes[i] = funRes[i] / funRes[i + 1];
                funRes.erase(funRes.begin() + i + 1);
                ops.erase(ops.begin() + i);
                i--;
            }
        }
        for (size_t i = 0; i < ops.length(); i++)
        {
            if (ops[i] == '+')
            {
                funRes[i] = funRes[i] + funRes[i + 1];
                funRes.erase(funRes.begin() + i + 1);
                ops.erase(ops.begin() + i);
                i--;
            }
            else if (ops[i] == '-')
            {
                funRes[i] = funRes[i] - funRes[i + 1];
                funRes.erase(funRes.begin() + i + 1);
                ops.erase(ops.begin() + i);
                i--;
            }
        }
        return getCoef() * pow(funRes[0], poww->f(x));
    }
};

int main()
{
    functions* ff;
    (*ff).coef();
    cout << log(10);
    return 0;
}