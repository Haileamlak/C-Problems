#include <iostream>
#include <vector>
using namespace std;

int fibbonaci(int);
int factorial(int);
bool palindrome(string, int, int);
void reverse(vector<int> &x, int s, int e);
void menu(), fact_menu(), fibb_menu(), palin_menu();
int minm(int x[], int s, int i, int j);
struct Try
{
    int a;
    string b;
};
int main()
{
    menu();
    return 0;
}
void reverse(vector<int> &x, int s, int e)
{
    if (s > e || s == e)
        return;
    int temp = x[s];
    x[s] = x[e];
    x[e] = temp;
    reverse(x, ++s, --e);
}

int minm(int x[], int s, int i, int j)
{
    if (j == s)
    {
        if (x[i] < x[j])
            return x[i];
        return x[j];
    }
    if (x[i] < x[j])
        return minm(x, s, i, j+1);
    return minm(x, s, j, j+1);
}

void menu()
{
    cout << "A) Fibonacci     B) Factorial     C) Check Palindrome\n\tYour Choice: ";
    char ch;
    cin >> ch;
    system("cls");
    switch (ch)
    {
    case 'A':
    case 'a':
        fibb_menu();
        break;
    case 'B':
    case 'b':
        fact_menu();
        break;
    case 'C':
    case 'c':
        palin_menu();
    default:
        break;
    }
    cout << "\nEnter 'Q' to quit or any other character to continue : ";
    char chq;
    cin >> chq;
    if (chq == 'Q' || chq == 'q')
    {
        cout << "Thank you!";
        exit(1);
    }
    system("cls");
}
int fibbonaci(int x)
{
    if (x == 1 || x == 2)
        return x - 1;
    return fibbonaci(x - 1) + fibbonaci(x - 2);
}
int factorial(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return x * factorial(x - 1);
}
bool palindrome(string x, int start, int end)
{
    if (start == end || start > end)
        return true;
    if (x[start] == x[end])
        return palindrome(x, ++start, --end);
    return false;
}
void fact_menu()
{
    cout << "Enter a number to know its facorial: ";
    int num;
    cin >> num;
    cout << "The factorial of " << num << " is " << factorial(num) << "." << endl;
}
void fibb_menu()
{
    cout << "Enter the length of the fibonacci series : ";
    int size;
    cin >> size;
    cout << "The first " << size << " elements of the fibonacci series are ";
    for (int i = 1; i <= size; i++)
    {
        cout << fibbonaci(i);
        i != size ? cout << " " : cout << ".\n";
    }
}
void palin_menu()
{
    cout << "Enter a word to check if it is a palindrome or not : ";
    string palin;
    cin >> palin;
    cout << "The word \"" << palin << "\"";
    palindrome(palin, 0, palin.length() - 1) ? cout << " is " : cout << " is not ";
    cout << "a palindrome.\n";
}