#include<iostream>
#include<iomanip>
using namespace std;

void readlist(float arr[], int size);
float find_range(float arr[], int size);
float find_mean(float arr[], int size);
float find_median(float arr[], int size);
float find_max(float arr[], int size);
float find_min(float arr[], int size);
void display(float arr[], int size);
void sort(float arr[], int size);

int main()
{
    int n;
    cout<<"Enter the number of elments : ";
    cin>>n;
    float arr[n];
    display(arr, n);
    return 0;
}
void readlist(float arr[], int size)
{
    cout<<"Enter the numbers below!\n";
    for (int i = 0; i < size; i++)
    {
        cout<<"num "<<i+1<<" = ";
        cin>>arr[i];
    }
}
float find_max(float arr[], int size)
{
    return arr[size-1];
}
float find_min(float arr[], int size)
{
    return arr[0];
}
float find_range(float arr[], int size)
{
    return arr[size-1] - arr[0];
}
float find_mean(float arr[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}
float find_median(float arr[], int size)
{
    if(size%2 == 0)   
        return (arr[(size-1)/2] + arr[(size-1)/2 + 1]) / 2;
    return arr[size/2];
}
void sort(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp;
        for (int j = i+1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void display(float arr[], int size)
{
    readlist(arr, size);
    sort(arr, size);
    cout<<"The list of the numbers in ascending order is : ";
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"The maximum number is "<<find_max(arr, size)<<endl;
    cout<<"The minimum number is "<<find_min(arr, size)<<endl;
    cout<<"The average value is "<<setprecision(2)<<find_mean(arr, size)<<endl;
    cout<<"The range value is "<<find_range(arr, size)<<endl;
    cout<<"The median value is "<<find_median(arr, size)<<endl;
}