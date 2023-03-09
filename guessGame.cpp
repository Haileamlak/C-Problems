#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    
    int n;
    char sec, x;
    string cows, bulls;
    vector<char>secret = {'A', 'B', 'C', 'D'};
    while(cout<<"enter a number: ",cin>>n)
    {
        for(int r = 0;r<4;++r)
        {
            secret.pop_back();
        }
        srand(n);
        for(;secret.size()<4;)
        {
            n = rand()%13;
            sec = char(65 + n);
            secret.push_back(sec);
        }
    bool finish = false;
    cout<<"enter your guess: \n";
    while(!finish)
    {
    int cow = 0, bull = 0;
    for(int i = 0;i < 4;++i)
    {
        bool fin = false;    
        cin>>x;
        if(x==secret[i])    bull++;
        for(int j = 0;j < 4 && !fin;++j)                //may be I made an error here using of fin
        {              
            if(x==secret[j] && x!=secret[i])
            { 
                cow++;fin = true; 
            }
            else {  }
        }
    }
    if(cow==1)cows="cow";
    else cows="cows";
    if(bull==1)bulls="bull";
    else bulls="bulls";
    if(bull==4)finish = true;
    else if(bull!=0||cow!=0)cout<<bull<<" "<<bulls<<" : "<<cow<<" "<<cows<<endl;
    else cout<<"no bulls no cows\n";
    }
    cout<<"you win!\n";
    } 
    
    return 0;
}