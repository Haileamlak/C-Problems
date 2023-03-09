#include <iostream>
#include <vector>

using namespace std;



int main()
{
    int m, n;
    cin >> m >> n;
    if (m < 1 && m > 16 && n < 1 && n > 16 && m > n)
        exit(1);
    cout << m * n / 2;
    return 0;
}