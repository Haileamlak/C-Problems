#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void primes();
void primes2();
int main()
{
    primes();
    return 0;
}
void primes()
{
    vector<int>pri {2};
    bool prime = true;
    for(int i=3;i<=100;++i)
    {
        for(int j=0;j<pri.size() && prime;++j)
            if(i%pri[j]==0)    prime = false;
        if(prime)   pri.push_back(i);
        prime = true;
    }
    cout<<"The prime numbers are ( ";
    for(int i=0;i<pri.size();++i)
        cout<<pri[i]<<" ";
    cout<<")";

}
void primes2()
{
    vector<int>prime;
    int n;
    cin>>n;
    for(int i = 2;i<=n;++i)    
    {
        if((i==2) || (i==3) || (i==5) || (i==7))    prime.push_back(i);
        else if((i%2==0) || (i%3==0) || (i%5==0) || (i%7==0))   {   }
        else 
        {    
            prime.push_back(i);
        }
    }   

    for(int x = 0;x < prime.size();++x)cout<<prime[x]<<" ";
}