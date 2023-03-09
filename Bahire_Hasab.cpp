#include <iostream>
#include <fstream>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include "Bahire_Hasab_lib.h"

// http://www.geez.org/Numerals/
// https://en.wikipedia.org/wiki/Ethiopian_calendar
using namespace std;

wchar_t የኢትዮጵያ_ቁጥሮች[] = {L' ', L'፩', L'፪', L'፫', L'፬', L'፭', L'፮', L'፯', L'፰', L'፱', L'፲', L'፳', L'፴', L'፵', L'፶', L'፷', L'፸', L'፹', L'፺', L'፻', L'፼'};

struct ቁጥር;
void የቀን_መቁጠሪያ(ቀን ቀን_1);
void ዋና_ማውጫ();
int string_to_int(wstring string_num);
wstring Arabic_to_ኢትዮ(wstring num);
istream &operator>>(istream &is, ቀን &x)
{
    int d, m, y;
    char ch1, ch2;
    is >> d >> ch1 >> m >> ch2 >> y;
    if (ch1 != '/' || ch2 != '/')
    {
        cout << "error : invalid date format";
        is.clear();
        return is;
    }
    x = ቀን{d, m, y};
    return is;
}
int main()
{
    _setmode(fileno(stdout), _O_U16TEXT);
    _setmode(fileno(stdin), _O_U16TEXT);
    ቀን ቀን_1 = ቀን(24, 8, 2014);
    wcout << L"ቀን አስገባ ( ቀን/ወር/ዓመት ) : ";
    cin >> ቀን_1._ቀን >> ቀን_1.ወር >> ቀን_1.አመት;
    የቀን_መቁጠሪያ(ቀን_1);
    wcout << L"ቀን አስገባ ( ቀን/ወር/ዓመት ) : ";
    cin >> ቀን_1._ቀን >> ቀን_1.ወር >> ቀን_1.አመት;
    የቀን_መቁጠሪያ(ቀን_1);
    // ዋና_ማውጫ();
    // wofstream Read_Menu{"mydatas.dat", ios_base::out | ios::binary};
    // wchar_t line[100];
    // wcin >> line;
    // while (Read_Menu)
    // {
    //     Read_Menu.read(line, 100);
    //     wcout.write(line,100);
    // }

    // Read_Menu.write(line, 11);
    // wcout << L"  ወደ : ";
    // wstring ch;
    // wcin >> ch;
    // wcout << የኢትዮጵያ_ቁጥሮች[(ch[1] - '0') - 1]; //'2'-'0'==2
    // wcout << Arabic_to_ኢትዮ(ch);
    return 0;
}

void የቀን_መቁጠሪያ(ቀን ቀን_1)
{
    wcout << L"\n\n\n\t\t\t";
    cout << ቀን_1;
    wcout << L'\n';
    int ዕለት_ማስያ = ((ቀን_1.አመት + 5500) + ((ቀን_1.አመት + 5500) / 4)) % 7;
    int ዕለት_ማስያ_ለወር = 2 * --ቀን_1.አመት;
    int temp_ቀን = (0 - ((ዕለት_ማስያ + ዕለት_ማስያ_ለወር) % 7)) % 7;
    wcout << L"\t\t ************************************** \t\n";
    wcout << L"\t\t|| sun  mon  tue  wed  thu  fri  sat  ||\t\n";
    for (int i = 0; i < 6; i++)
    {
        wcout << L"\t\t|| ";
        for (int j = temp_ቀን; j <= temp_ቀን + 6; j++)
        {
            wcout << L" ";
            if (j < 1)
            {
                wcout << L"    ";
                continue;
            }
            if (j > 30)
            {
                wcout << L"    ";
                continue;
            }
            if (j < 10)
                wcout << 0;
            wcout << j << L"  ";
        }
        wcout << L"||\t" << endl;
        temp_ቀን += 7;
    }
    wcout << L"\t\t **************************************\n";
}
void ዋና_ማውጫ()
{
    _setmode(fileno(stdout), _O_U16TEXT);
    _setmode(fileno(stdin), _O_U16TEXT);
    wifstream Read_Menu{"Menu.txt"};
    wstring line;
    while (getline(Read_Menu, line))
        wcout << line << endl;
    wcout << L"ምርጫህን አስገባ : ";
    char ch;
    cin >> ch;
    switch (ch)
    {
    case '1':
    {
        ቀን ቀን_1;
        wcout << L"ቀን አስገባ ( ቀን/ወር/ዓመት ) : ";
        // cin >> ቀን_1;
        የቀን_መቁጠሪያ(ቀን_1);
        break;
    }
    case '2':
        //     Holidays();
        //     break;
        // case '3':
        //     Fastings();
        //     break;
        // case '4':
        //     Basic_Info();
        //     break;
        // case '5':
        //     Date_Conversion();
        //     break;
        // case '6':
        //     ዕለት();
        break;
    }
}

struct ቁጥር
{
    wstring ኢትዮ_ቁጥር;
    int Arabic_number;
    ቁጥር(wstring ethio_num, int arabic_num)
        : ኢትዮ_ቁጥር{ethio_num}, Arabic_number{arabic_num} {}
};

void conversion(ቀን x)
{
}

// istream &operator>>(istream &is, ቁጥር &num)
// {
//     wstring num1;
//     int num2;
//     cin >> num2;
//     if (num2 < 0)
//     {
//         cerr << "error : Invalid number!";
//         exit(2);
//     }
// }

// wistream &operator>>(wistream &is, ቁጥር &number)
// {
//     wstring num;
//     is >> num;
//     number.Arabic_number = string_to_int(num);
//     number.ኢትዮ_ቁጥር = Arabic_to_ኢትዮ(num);
//     return is;
// }

// int ኢትዮ_to_Arabic(wstring num)
// {
//     vector<wstring> temp;
//     wstring line;
//     if (num.length() % 2 == 1)
//     {
//         temp.push_back(num[0])
//             num.erase(num.begin());
//     }
//     for (int i = num.length() - 1; i >= 0; i - 2)
//         temp.push_back(num[i] + num[i - 1]);
// }

wstring Arabic_to_ኢትዮ(wstring num)
{
    wstring ኢትዮ_num;
    for (int i = num.length() - 1, c = 0; i >= 0; i -= 2, c += 2)
    {
        if (c == 0)
            ኢትዮ_num = የኢትዮጵያ_ቁጥሮች[int(num[i - 1]) + 10] + የኢትዮጵያ_ቁጥሮች[int(num[i])];
        if (c > 0 && c % 2 != 0)
            ኢትዮ_num = የኢትዮጵያ_ቁጥሮች[int(num[i - 1]) + 10] + የኢትዮጵያ_ቁጥሮች[int(num[i])] + L"፻" + ኢትዮ_num;
        if (c > 0 && c % 2 == 0)
            ኢትዮ_num = የኢትዮጵያ_ቁጥሮች[int(num[i - 1]) + 10] + የኢትዮጵያ_ቁጥሮች[int(num[i])] + L"፼" + ኢትዮ_num;
    }
    return ኢትዮ_num;
}

// ቀን convert(ቀን x)
// {
// }

// Color of the console
// HANDLE console_color;
// console_color = GetStdHandle(
//     STD_OUTPUT_HANDLE);
// SetConsoleTextAttribute(console_color, 56);

// int string_to_int(wstring string_num)
// {
//     int int_num = 0, tenth = 1;
//     for (int k = string_num.size() - 1; k >= 0; --k)
//     {
//         if(!isdigit(string_num[k] - '0') && (string_num[k] - '0')<0)
//             exit(4);
//         int_num += (string_num[k] - '0') * tenth;
//         tenth *= 10;
//     }
//     return int_num;
// }

enum Month
{
    September,
    October,
    November,
    December,
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    Pagume
};