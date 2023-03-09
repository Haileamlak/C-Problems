#include "std_lib.cpp"
using namespace std;

/*

int receive()
{
    int x;
    cin>>x;
    return x;
}
 
int below()
{
    int res;
    int a = receive();
    int b = receive();
    if(a<0 || a<b || b<0 || b==0 || a==0) error("factorial expected");
    for(int i=a-1;i>=a-b;--i)
    {
        a *=i;
    }
    res = a;
    return res;
}
*/
int main ()
{

    // cout<<below();
    there:
    char number;
    int num = 0, multiply = 1;
    string text;
    vector<char> collect;
    cout<<"enter a number not greater than four digits(enter 'q' to exit) : ";
    while(cin>>number)
    {   
        if(number == 'q') error("finish");
        if(number == ';') break;  
        else collect.push_back(number);
    }
    for(int k=collect.size()-1;k>=0;--k)
    {
        num +=(collect[k]-'0')*multiply;
        multiply *=10;
    }
        cout<<num<<" is ";
    for(int j=0;j<collect.size();++j)
    {   
        if(j==3) text = "ones";
        if(j==2) text = "tens";
        if(j==1) text = "hundreds";
        if(j==0) text = "thousands";
        if(j==collect.size()-1) cout<<collect[j]<<" "<<text<<'.';
        else cout<<collect[j]<<" "<<text<<" and ";  
    }
    cout<<endl;
    goto there;
    return 0;
}