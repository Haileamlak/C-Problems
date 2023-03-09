#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, res1, res2;
    cout << "To solve a quadratic equation\nenter a: "; // ax2 + bx + c
    cin >> a;
    cout << "enter b: ";
    cin >> b;
    cout << "enter c: ";
    cin >> c;
    if (((b * b) - (4 * a * c)) < 0)
    {
        cout << "no solution!";
    }
    else
    {
        res1 = (-b + sqrt(b * b - (4 * a * c))) / (2 * a);
        res2 = (-b - sqrt(b * b - (4 * a * c))) / (2 * a);
        cout << "The solution set is {" << res1 << ", " << res2 << "}";
    }
    return 0;
}

// int score;
// int sum = 0;
// int count = 1;
// int n;
// cout << "enter the number of students : ";
// cin >> n;
// while (count <= n)
// {
//     cin >> score;
//     if (score >= 0 && score <= 100)
//     {
//         sum += score;
//     }
//     count++;
// }
// cout << "the average score is : " << (sum / n);