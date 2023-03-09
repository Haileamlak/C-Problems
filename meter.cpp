#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{   vector<double>far;
    int j = 0;
    double sum = 0;
    double max, min, x;
    string unit;
    
    while(cin>>x>>unit){
        ++j;
        int i = 0;
        while(i < far.size(),++i){
        far[i];}
        double lg;
        if(unit == "m") {lg = x;}
        if(unit == "cm"){lg = 0.01*x;}  
        if(unit == "in"){lg = 0.0254*x;}
        if(unit == "ft"){lg = 0.3048*x;}
        far.push_back(lg);
        sum +=lg;
        sort(far.begin(), far.end());
        max = far[far.size() - 1];
        min = far[0];
   }    for(int c = 0;c<far.size();++c) cout<<far[c]<<", ";
        cout<<"\nthe number of values: "<<j;
        cout<<"\nthe sum of the values : "<<sum<<"m";
        cout<<"\nthe maximum value: "<<max<<"m";
        cout<<"\nthe minimum value: "<<min<<"m";
    return 0;
}