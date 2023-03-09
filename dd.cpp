#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, m, a;
    cin >> n >> m >> a;
    cout << round(double(n) / a) * round(double(m) / a);
    return 0;
}