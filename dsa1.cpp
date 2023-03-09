#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_array10(ostream &os, int *s);
void print_array(ostream &os, int *a, int n);
void print_vector(ostream &os, vector<int> a);
void toLower(char *s);
char *findx(const char *s, const char *x);

struct God
{
    string name, mythology, vehicle, weapon;
    God(string n, string m, string v, string w) : name(n), mythology(v), vehicle(v), weapon(w)
    {
    }
};

struct Link
{
    God value;
    Link *prev;
    Link *succ;
};
int main()
{
    int lac[20]; // local array; “lives” until the end of scope

    lac[7] = 'a';
    *lac = 'b'; // equivalent to lac[0]='b'

    lac[-2] = 'b';  // huh?
    lac[200] = 'c'; // huh?
    cout << lac[200];
    return 0;
}

char *findx(const char *s, const char *x)
{
    for (size_t i = 0; *s != '0'; i++)
    {
        if (s[i] == *x)
        {
            for (size_t j = 0; x[j] == s[i + j]; j++)
            {
                if (x[j + 1] == 0)
                    return (const_cast<char *>(s) + i);
            }
        }
    }
    return nullptr;
}

char *strdup(const char *a)
{

    char *n = new char[strlen(a)];
    n = const_cast<char *>(a);
    return n;
}

void toLower(char *s)
{
    while (*s)
    {
        *s = char(int(*s) < 97 ? 97 + (int(*s) - 65) : int(*s));
        s++;
    }
}

void print_array10(ostream &os, int *s)
{
    for (int i = 0; i < 11; i++)
    {
        os << s[i] << endl;
    }
}

void print_array(ostream &os, int *a, int n)
{
    for (int i = 0; i < n; i++)
        os << a[i] << endl;
}

void print_vector(ostream &os, vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        os << a[i] << endl;
    }
}