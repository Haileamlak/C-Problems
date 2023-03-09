#include <iostream>
#include <iomanip>
using namespace std;

int add(int, int);
int sub(int, int);
int mult(int, int);
float divv(int, int);
void accept();
void menu(int, int);

int main()
{
    cout << "****************************************************\n"
         << "\tWelcome to our simple calculator!\n"
         << "You can do any of the four basic arithmetic operations here.\n"
         << "****************************************************\n";
    while (true)
    {
        accept();
        cout << "****************************************************\n";
        cout << "Enter 'C' to continue or any other character to quit.\n"
             << "\tAnswer : ";
        char ch;
        cin >> ch;
        if (ch == 'c' || ch == 'C')
            ;
        else
            break;
        system("cls");
        cout << "****************************************************\n";
    }
    return 0;
}
void accept()
{
    int x, y;
    cout << "Enter two integers : ";
    cin >> x >> y;
    menu(x, y);
}
void menu(int a, int b)
{
    cout << "What operations do you want to do with these numbers?\n"
         << "A) addition  B) subtraction  C) multiplication  D) division\n"
         << "\tAnswer : ";
    char ch;
    cin >> ch;
    switch (ch)
    {
    case 'A':
    case 'a':
        cout << "The sum of the numbers " << a << " and " << b << " is " << add(a, b) << endl;
        break;
    case 'B':
    case 'b':
        cout << "The difference of the numbers " << a << " and " << b << " is " << sub(a, b) << endl;
        break;
    case 'C':
    case 'c':
        cout << "The product of the numbers " << a << " and " << b << " is " << mult(a, b) << endl;
        break;
    case 'D':
    case 'd':
        if (b == 0)
        {
            cerr << "error: divide by zero!";
            exit(2);
        }
        cout << "The quotient of the numbers " << a << " and " << b << " is " << setprecision(2) << divv(a, b) << endl;
        break;
    default:
        cerr << "error: unexpected character!";
        exit(1);
        break;
    }
}
int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int mult(int x, int y)
{
    return x * y;
}
float divv(int x, int y)
{
    return float(x) / float(y);
}