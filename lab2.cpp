#include <iostream>
#include "lab5.h"

using namespace std;
void perfect();

int main()
{
    menu();
    // perfect();
    return 0;
}
void perfect()
{
    int sum = 0;
    cout << "The perfect numbers in the range [1 - 1000] are ";
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j < i; ++j)
            if (i % j == 0)
                sum += j;
        if (sum == i)
            cout << i << " ";
        sum = 0;
    }
}