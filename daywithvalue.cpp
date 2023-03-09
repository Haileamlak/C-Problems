#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<ctime>
#define double float
using namespace std;

int main()
{
    vector<float>Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday;
    string day_of_the_week;
    float day_value, Mon_sum = 0, Tue_sum = 0, Wed_sum = 0, Thu_sum = 0, Fri_sum = 0, Sat_sum = 0, Sun_sum = 0;
    bool finish = false;
    while(!finish)
    {
    cout<<"enter day of the week with its value: ";
    cin>>day_of_the_week>>day_value;
    if(day_of_the_week=="monday"||day_of_the_week=="mon")Monday.push_back(day_value);
    if(day_of_the_week=="tuesday"||day_of_the_week=="tue")Tuesday.push_back(day_value);
    if(day_of_the_week=="wednesday"||day_of_the_week=="wed")Wednesday.push_back(day_value);
    if(day_of_the_week=="thursday"||day_of_the_week=="thu")Thursday.push_back(day_value);
    if(day_of_the_week=="friday"||day_of_the_week=="fri")Friday.push_back(day_value);
    if(day_of_the_week=="saturday"||day_of_the_week=="sat")Saturday.push_back(day_value);
    if(day_of_the_week=="sunday"||day_of_the_week=="sun")Sunday.push_back(day_value);
    if(day_of_the_week=="|"||day_value==0)finish = true;
    }
    cout<<"monday has values: ";

    for(int a = 0;a<Monday.size();++a)
    {
      Mon_sum+=Monday[a]; cout<<Monday[a]<<", ";
    }
    cout<<"\nand their sum is "<<Mon_sum<<endl;
    cout<<"tuesday has values: ";
    for(int a = 0;a<Tuesday.size();++a)
    {
      Tue_sum+=Tuesday[a]; cout<<Tuesday[a]<<", ";
    }
    cout<<"\nand their sum is "<<Tue_sum<<endl;
    cout<<"wednesday has values: ";
    for(int a = 0;a<Wednesday.size();++a)
    {
      Wed_sum+=Wednesday[a]; cout<<Wednesday[a]<<", ";
    }
    cout<<"\nand their sum is "<<Wed_sum<<endl;
    cout<<"thursday has values: ";
    for(int a = 0;a<Thursday.size();++a)
    {
       Thu_sum+=Thursday[a]; cout<<Thursday[a]<<", ";
    }
    cout<<"\nand their sum is "<<Thu_sum<<endl;
    cout<<"friday has values: ";
    for(int a = 0;a<Friday.size();++a)
    {
       Fri_sum+=Friday[a]; cout<<Friday[a]<<", ";
    }
    cout<<"\nand their sum is "<<Fri_sum<<endl;
    cout<<"saturday has values: ";
    for(int a = 0;a<Saturday.size();++a)
    {
       Sat_sum+=Saturday[a]; cout<<Saturday[a]<<", ";
    }
    cout<<"\nand their sum is "<<Sat_sum<<endl;
    cout<<"sunday has values: ";
    for(int a = 0;a<Sunday.size();++a)
    {
       Sun_sum+=Sunday[a]; cout<<Sunday[a]<<", ";
    }
    cout<<"\nand their sum is "<<Sun_sum<<endl;
    cout<<"Thank you!"<<endl;
    return 0;
}