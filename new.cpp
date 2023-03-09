#include <iostream>
#include <string>
#include <fcntl.h>
#include <fstream>
#include <conio.h>
#include <io.h>
using namespace std;
wstring ወራት[] = {L"መ ስከረም", L"ጥቅምት", L"ኅዳር", L"ታኅሣሥ", L"ጥር", L"የካቲት", L"መጋቢት", L"ሚያዝያ", L"ግንቦት", L"ሰኔ", L"ሐምሌ", L"ነሐሴ", L"ጳጉሜ"};

wstring get_ወር(int month)
{
    return ወራት[month];
}
struct Date
{
    int day, month, year;
    Date(int d, int m, int y);
    Date()
        : day(01), month(01), year(2014) {}
    bool ዘመነ_ዮሐንስ(int yy);
};
void ዕለት(Date);
Date::Date(int d, int m, int y)
    : day(d), month(m), year(y)
{
    if (d <= 0 || d > 30 || m <= 0 || m > 13 || (m == 13 && !Date::ዘመነ_ዮሐንስ(y) && d > 5) || (m == 13 && Date::ዘመነ_ዮሐንስ(y) && d > 6))
    {
        wcerr << L"error : Invalid Date!\n";
        exit(1);
    }
}
bool Date::ዘመነ_ዮሐንስ(int yy)
{
    if (yy % 4 == 0)
        return true;
    return false;
}
wistream &operator>>(wistream &is, Date &x)
{
    int d, m, y;
    wchar_t ch1, ch2;
    is >> d >> ch1 >> m >> ch2 >> y;
    if (ch1 != '/' || ch2 != '/')
    {
        wcout << "error : invalid date format";
        is.clear();
        return is;
    }
    x = Date{d, m, y};
    return is;
}
wostream &operator<<(wostream &os, Date &x)
{
    wcout << get_ወር(x.month - 1) << L" " << x.day << L" " << x.year << L" ዓ.ም";
    return os;
}

int main()
{
    _setmode(fileno(stdout), _O_U8TEXT);
    _setmode(fileno(stdin), _O_U8TEXT);
    cout << "Enter the date like  --23/05/2017--OR --23/tir/2017--" << endl;
    int n;
    string line(50, '-');
    Date input_date, output_date;
    string d1, m1, y1;
    wcin >> input_date;
    if (input_date.year % 4 == 3) // stoi(y) % 4 == 3
        n = 6;
    else
        n = 5;
    if (input_date.month == 1)
    {
        if (input_date.day >= 1 && input_date.day <= 20)
            output_date = Date{input_date.day + 10, 1, input_date.year + 7};
        wcout << output_date;
    }
    return 0;
}