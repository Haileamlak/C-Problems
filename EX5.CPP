#include<iostream>

using namespace std;
int x1 = 9;
void fun(){
    int x2 = 5;
    int x4 = 6;
    int x5 = 6;
    cout <<(&x1> &x2)<<endl;
    int *x3 = new int(2);
    int *x6 = new int[3]{1, 2, 3};
    cout <<(&x1> x3)<<endl;
    cout << (&x2 > x3) << endl;
    cout << (&x4) << endl;
    cout << (&x5) << endl;
    cout << (&x6[0]) << endl;
    cout << (&x6[1]) << endl;
    cout << (&x6[2]) << endl;
}
int main()
{
    cout << &x1<<endl;
    fun();

    return 0;
}