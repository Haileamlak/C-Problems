#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
int fun(string s1, string s2);

int main()
{
    cout << fun("buy", "bye");
    return 0;
}

int fun(string s1, string s2)
{
    int count = 0, count1 = 0, count2 = 0, repeat = 0;
    for (size_t i = 0; i < s1.length(); i++)
        for (size_t j = 0; j < s2.length(); j++)
            if (s1[i] == s2[j])
            {
                s2 = s2.substr(0, j) + s2.substr(j + 1);
                i++;
                j = 0;
                count++;
            }

    return s1.length() - count;
}