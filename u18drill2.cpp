#include <iostream>
#include <vector>

using namespace std;

vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
void f(vector<int> vec)
{
    vector<int> lv(vec.size());
    lv = gv;
    for (size_t i = 0; i < lv.size(); i++)
    {
        cout << lv[i] << " ";
    }
    vector<int> lv2 = vec;
    for (size_t i = 0; i < lv.size(); i++)
    {
        cout << lv2[i] << " ";
    }
}

char *strdup(const char *c);
char *findx(const char *s, const char *x);
int strcmp(const char *s1, const char *s2);
string catdot(const string &s1, const string &s2, const string &s3);
int main()

{
    // f(gv);
    // vector<int> vv;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     if (i == 0)
    //         vv.push_back(i+1);
    //     else
    //         vv.push_back((i + 1) * vv[i - 1]);
    //     /* code */
    //     // cout << vv[i] << " - ";
    // }
    // f(vv);
    char *a = new char[5]{'q', 'w', 'r', 't'};
    char *b = "qrty";
    string c = "sep";
    cout << catdot(a, b, c);
    return 0;
}

string catdot(const char s1[], const char s2[], const char s3[])
{
    char *res = new char[23];
    res = s1 + s2 + s3;
    return res;
}
int strcmp(const char *s1, const char *s2)
{

    if (!*s1 && !*s2)
        return 0;
    else if (*s1 == *s2)
        return strcmp(s1 + 1, s2 + 1);
    else
        return *s1 - *s2;
}
char *findx(const char *s, const char *x)
{
    for (size_t i = 0; *(s + i); i++)
    {
        if (*(s + i) == *x)
        {
            size_t j = 0;
            for (; *(x + j); j++)
            {
                if (*(s + i + j) != *(x + j))
                    break;
            }
            if (!*(x + j))
                return const_cast<char *>(s + i);
        }
    }
    return nullptr;
}
char *strdup(const char *c)
{
    size_t i = 0;
    for (; *(i + c); i++)
    {
        cout << *(i + c) << endl;
    }

    char *cl = new char[i];
    // while (*c)
    // {

    //     c++;
    //     cl++;
    // }
    for (size_t i = 0; *(i + cl); i++)
    {
        *(i + cl) = *(c + i);
    }
    return cl;
}