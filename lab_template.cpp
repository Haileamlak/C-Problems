#include<iostream>
#include<fstream>
using namespace std;

template<class T>
T square(T x, T y)
{
    return x*y;
}
int main()
{
    fstream file{"mydata.txt"};
    char x[10];
    int y;
    char ch = EOF;
    while(file)
    {
        y = file.get();
        cout<<y<<" ";
        // if(x=='6')
            // cout<<endl<<file.gcount();

    }
    return 0;
}