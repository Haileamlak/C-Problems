#include <iostream>
#include <vector>

using namespace std;

int ga[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int arr[], int asize)
{
    int la[10];
    for (size_t i = 0; i < 10; i++)
    {
        la[i] = ga[i];
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << la[i] << endl;
    }
    int *p = new int[asize];
    for (size_t i = 0; i < asize; i++)
    {
        p[i] = arr[i];
    }

    for (size_t i = 0; i < asize; i++)
    {
        cout << p[i] <<" - "<< endl;
    }
    delete[] p;
}
int main()

{

    f(ga, 10);
    int aa[10];
    for (size_t i = 0; i < 10; i++)
    {
        if (i == 0)
            aa[i] = i+1;
        else
            aa[i] = aa[i - 1] * (i+1);

        /* code */
    }
    f(aa, 10);

    return 0;
}
