#include <iostream>
#include <vector>

#include <string>

#include <sstream>

using namespace std;

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

void insertionSort1(int n, vector<int> arr)
{
    int temp = arr[n - 1];
    bool found = false;
    for (int i = n - 2; i >= -1 && !found; i--)
    {
        if (i == -1)
            arr[0] = temp;
        else if (arr[i] < temp)
        {
            arr[i + 1] = temp;
            found = true;
        }
        else
            arr[i + 1] = arr[i];
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

vector<int> countingSort(vector<int> arr)
{
    vector<int> newArr(100);
    int size = arr.size();
    for (size_t i = 0; i < size; i++)
    {
        newArr[arr[i]]++;
    }
    return newArr;
}

string sortSentence(string s)
{
    stringstream ss{s};
    string temp = "", result = "";
    vector<string> res(9);
    int c = 0;
    while (ss >> temp)
    {
        int index = temp.back() - '0';
        temp.pop_back();
        res[index - 1] = temp;
        c++;
    }
    for (size_t i = 0; i < c; i++)
    {
        result += res[i] + " ";
    }
    result.pop_back();
    return result;
}

int findTheWinner(int n, int k)
{
    int start = 1,remo=-1;
    vector<int> res(n+1);
    for (size_t i = 0; i < n; i++)
    {
        start += k;
        if(start>n)
            start %= n;
        remo = start  - 1;
        res.erase(res.begin() + remo);
    }
    return res[1];
}

int main()
{
    int n = 14;
    vector<int> ar = {1, 3, 5, 9, 13, 22, 27, 35, 46, 51, 55, 83, 87, 23};

    // insertionSort1(n, ar);
    // countingSort(ar);

    string s = "fdgf dfgg";
    sortSentence(s);
    return 0;
}
