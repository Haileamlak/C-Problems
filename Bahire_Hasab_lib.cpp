#include <iostream>
#include <vector>
#include <fcntl.h>
#include <iomanip>

using namespace std;
string greg_months[] = {"September", "October", "November", "December", "January", "February", "March", "April", "May", "June", "July", "August"};
// ቁጥር የኢትዮጵያ_ቁጥሮች[20] = {{L"፩", 1}, {L"፪", 2}, {L"፫", 3}, {L"፬", 4}, {L"፭", 5}, {L"፮", 6}, {L"፯", 7}, {L"፰", 8}, {L"፱", 9}, {L"፲", 10}, {L"፳", 20}, {L"፴", 30}, {L"፵", 40}, {L"፶", 50}, {L"፷", 60}, {L"፸", 70}, {L"፹", 80}, {L"፺", 90}, {L"፻", 100}, {L"፼", 10000}};
wstring ወራት[] = {L"መ ስከረም", L"ጥቅምት", L"ኅዳር", L"ታኅሣሥ", L"ጥር", L"የካቲት", L"መጋቢት", L"ሚያዝያ", L"ግንቦት", L"ሰኔ", L"ሐምሌ", L"ነሐሴ", L"ጳጉሜ"};
wstring የሳምንቱ_ዕለታት[] = {L"ሠኞ", L"ማግሠኞ", L"ረቡዕ", L"ሀሙስ", L"ዐርብ", L"ቅዳሜ", L"እሑድ"};
// wchar_t የኢትዮጵያ_ቁጥሮች[] = {L'፩', L'፪', L'፫', L'፬', L'፭', L'፮', L'፯', L'፰', L'፱', L'፲', L'፳', L'፴', L'፵', L'፶', L'፷', L'፸', L'፹', L'፺', L'፻', L'፼'};

wstring get_ወር(int month)
{
    return ወራት[month];
}

// wchar_t get_ቁጥር(int Arabic_number)
// {
//     return የኢትዮጵያ_ቁጥሮች[Arabic_number];
// }

struct ቀን
{
    int _ቀን, ወር, አመት;
    ቀን(int d, int m, int y);
    ቀን()
        : _ቀን(01), ወር(01), አመት(2014) {}
    bool ዘመነ_ዮሐንስ(int yy);
    ቀን add_ቀን(int dds)
    {
        int yy = አመት + (dds / 365);
        int mm = ወር + (dds % 365) / 30;
        int dd = _ቀን + ((dds % 365) % 30);
        return ቀን(dd, mm, yy);
    }
};

ቀን::ቀን(int d, int m, int y)
    : _ቀን(d), ወር(m), አመት(y)
{
    if (d <= 0 || d > 30 || m <= 0 || m > 13 || (m == 13 && d > 5) || (m == 13 && ቀን::ዘመነ_ዮሐንስ(y) && d > 6))
    {
        cerr << "error : Invalid ቀን!";
        exit(1);
    }
}
bool ቀን::ዘመነ_ዮሐንስ(int yy)
{
    if (yy % 4 == 0)
        return true;
    return false;
}

// struct ቀን
// {
//     int day, month, year;
//     ቀን(int y, Month m, int d); // check for valid date and initialize
//     ቀን()
//         : day(01), month(01), year(2022) {}
//     void add_day(int n);
//     void add_month(int n);
//     void add_year(int n);
// };

wstring Ethio_letters[] = {L"፩", L"፪", L"፫", L"፬", L"፭", L"፮", L"፯", L"፰", L"፱", L"፲", L"፲፩", L"፲፪", L"፲፫", L"፲፬", L"፲፭", L"፲፮", L"፲፯", L"፲፰", L"፲፱", L"፳", L"፳፩", L"፳፪", L"፳፫", L"፳፬", L"፳፭", L"፳፮", L"፳፯", L"፳፰", L"፳፱", L"፴"};

wstring get_geez(int x)
{
    return Ethio_letters[x];
}
/*
int main()
{
    int tempDay = -3;
    _setmode(fileno(stdout), _O_U16TEXT);
    _setmode(fileno(stdin), _O_U16TEXT);
    for (int i = 0; i < 6; i++)
    {
        wcout << L'\t';
        for (int j = tempDay; j <= tempDay + 6; j++)
        {
            wcout << setw(3) << L"  ";
            if (j < 1)
            {
                wcout << setw(3) << L"    ";
                continue;
            }
            if (j > 30)
            {
                wcout << setw(3) << L" ";
                continue;
            }
            // if (j < 10)
            //     cout << 0;

            wcout << setw(3) << get_geez(j - 1) << L" ";
        }
        wcout << L"\n\n";
        tempDay += 7;
    }

    wcout << L"test";
    return 0;
}
*/
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
ostream &operator<<(ostream &os, ቀን &x)
{
    wcout << get_ወር(x.ወር - 1) << L" " << x._ቀን << L" " << x.አመት << L" ዓ.ም";
    return os;
}