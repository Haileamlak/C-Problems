#include "std_lib.cpp"

using namespace std;

void invert();
void numstar();
void quad();
void quadrant();
void mode();
void grade();
void quadEquation();
void GCFLCM();
void number();
void time(), arraySum(), matrixMult(), sort();
void bill(), numseq(), weekly_ave_temp(), example();
void arRay(), transpose(), matrix(), inverseArray();
void mode2();
void make_mode(int &num, int &count, vector<int> &mode, vector<int> &rept);
class gcflcm
{
};
class bad
{
};

int referrence(int &x)
{
    x *= 2;
    return x;
}

class Point
{
public:
    double X;
    double Y;
};

int main()
try
{
    /* vector<Point> original_points;
     for (int i = 0; i < 7; i++)
     {
         int x, y;
         cin >> x >> y;
         Point a;
         a.X = x;
         a.Y = y;
         original_points.push_back(a);
     }

     cout << "please enter output file name : ";
     string oname;
     cin >> oname;
     ofstream ost{oname};
     if (!ost)
         cerr << "can't open output file ," << oname << endl;
     for (int i = 0; i < 7; ++i)
     {
         ost << "(" << original_points[i].X << ", " << original_points[i].Y << ")\n";
     }
     cout << "please enter input file name : ";
     string iname;
     cin >> iname;
     ifstream ist{iname};
     vector<Point> processed_points;
     for (int i = 0; i < 7; i++)
     {
         int x, y;
         ist >> x >> y;
         Point a;
         a.X = x;
         a.Y = y;
         processed_points.push_back(a);
     }
     for (int i = 0; i < 7; ++i)
     {
         cout << "(" << original_points[i].X << ", " << original_points[i].Y << ")\n";
     }
     for (int i = 0; i < 7; ++i)
     {
         cout << "(" << processed_points[i].X << ", " << processed_points[i].Y << ")\n";
     }*/
    int sum = 0;
    ifstream ist{"mydata.txt"};
    if(!ist) error("Can't open input file");
    for(int x;ist>>x;)
        sum += x;
    cout<<sum;

    return 0;
}
catch (bad)
{
    cerr << "baddddddd";
    return 1;
}
catch (gcflcm)
{
    cerr << "Sorry! can not find GCF and LCM";
    return 2;
}
catch (exception &e)
{
    cerr << e.what();
    return 3;
}
catch (...)
{
    cerr << "unknown error";
    return 4;
}

void sort()
{
    int c = 0, rept = 0, r = 0, n;
    cout << "Enter the number of elements : ";
    cin >> n;
    int arr[n], sort[n];
    bool repetted = false;
    cout << "Enter the numbers below!\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] == rept && repetted)
                continue;
            if (arr[i] == arr[j])
                r++;
            if (arr[i] >= arr[j])
                c++;
            else
                ;
        }
        if (r == 1)
            sort[c - r] = arr[i];
        else if (r >= 1)
        {
            for (int x = 1; x <= r; ++x)
                sort[c - x] = arr[i];
            rept = arr[i];
            repetted = true;
        }
        else ;
        c = 0;
        r = 0;
    }
    for (int y : sort)
        cout << y << " ";
}

void example()
{
    char list[3]{'a', 'b'};
    cout << list[1];
}

void numseq()
{
    int x, a, temp, count;
    int i = 10000;
    cout << "Please enter an integer number (its digit must <= 5)  : ";
    cin >> x;
    for (int j = 0; j < 6; ++j)
    {
        count = 0;
        temp = x;
        for (; x > 0; i /= 10)
        {
            a = x / i;
            cout << a << '\t';
            count++;
            x %= i;
        }
        int z = pow(10, count - 1);
        x = temp % z;
        i = z / 10;
        count--;
        cout << endl
             << endl
             << '\n';
    }
}

void GCFLCM()
{
    int x, y, GCF, LCM, z;
    bool end = false;
    cout << "Please enter two numbers to knoW their GCF and LCM\n\tnumber 1 : ";
    cin >> x;
    cout << "\tnumber 2 : ";
    cin >> y;
    if (x < 0 || y < 0)
        throw gcflcm{};
    if (x == 0)
    {
        GCF = y;
        LCM = 0;
    }
    else if (y == 0)
    {
        GCF = x;
        LCM = 0;
    }
    else
    {
        if (x > y)
            z = x;
        else
            z = y;
        while (z > 0 && !end)
        {
            if (x % z == 0 && y % z == 0)
            {
                GCF = z;
                LCM = (x * y) / z;
                end = true;
            }
            z--;
        }
    }
    cout << "The GCF of the numbers is " << GCF << endl;
    cout << "The LCM of the numbers is " << LCM;
}

void matrixMult()
{
    int sum = 0, row1, row2, column1, column2;
    cout << "Enter row and column size of your matrix!\n";
    cout << setw(20) << "row : ";
    cin >> row1;
    cout << setw(20) << "column : ";
    cin >> column1;
    int matA[row1][column1];
    cout << "Enter your matrix below : \n";
    for (int i = 0; i < row1; ++i)
    {
        for (int j = 0; j < column1; ++j)
            cin >> matA[i][j];
    }
    cout << "Enter row and column size of your another matrix!\n"
         << "(caution : column size must equal to row size of the previos matrix\n";
    cout << setw(20) << "row : ";
    cin >> row2;
    cout << setw(20) << "column : ";
    cin >> column2;
    int matB[row2][column2], Mat[row1][column2];
    ;
    cout << "Enter your matrix below : \n";
    for (int i = 0; i < row1; ++i)
    {
        for (int j = 0; j < column1; ++j)
            cin >> matB[i][j];
    }
    for (int r = 0; r < row1; ++r)
    {
        for (int i = 0; i < column2; ++i)
        {
            for (int c = 0; c < 2; c++)
            {
                sum += (matA[r][c] * matB[c][i]);
            }
            Mat[r][i] = sum;
            sum = 0;
        }
        sum = 0;
    }
    cout << endl
         << "The product of the matrices is \n";
    for (auto &row : Mat)
    {
        for (auto &column : row)
            cout << setw(4) << column << " ";
        cout << endl;
    }
}

void matrix()
{
    int max, min, sum = 0, range, Matrix[5];
    float average;
    for (int i = 0; i < 5; ++i)
        cin >> Matrix[i];

    for (int j = 0; j < 5; ++j)
    {
        for (int k = 0; k < 5; ++k)
        {
            if (Matrix[j] < Matrix[k])
                break;
            if (k == 4)
            {
                max = Matrix[j];
                goto below;
            }
        }
    }
below:
    for (int j = 0; j < 5; ++j)
    {
        for (int k = 0; k < 5; ++k)
        {
            if (Matrix[j] > Matrix[k])
                break;
            if (k == 4)
            {
                min = Matrix[j];
                goto under;
            }
        }
    }
under:
    for (int i = 0; i < 5; ++i)
        sum += Matrix[i];
    average = sum / 5.0;
    range = max - min;
    cout << "The maximum value is " << max << '.';
    cout << "\nThe minimum value is " << min << '.';
    cout << "\nThe range of the values is " << range << '.' << endl;
    cout << "The average of the values is " << average << '.';
}

void weekly_ave_temp()
{
    float daily_temp, sum_temp, ave_temp, weekly_temp[7];
    for (int i = 0; i < 7; ++i)
    {
        cout << "\ntemp 0f day " << i + 1 << " = ";
        cin >> daily_temp;
        weekly_temp[i] = daily_temp;
    }
    for (int i = 0; i < 7; ++i)
        sum_temp += weekly_temp[i];
    ave_temp = sum_temp / 7;
    cout << "\nThe weekly average temperature is " << ave_temp;
}

void inverseArray()
{

    int temp, arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 5; ++i)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + 9 - i);
        *(arr + 9 - i) = temp;
    }
    for (int x : arr)
        cout << x << " ";
}

void arraySum()
{
    int rowSum = 0, columnSum = 0, rcNum = 1, sizeM,
        mainSum = 0, counterSum = 0;
    cout << "Enter the size of your square matrix not greater than 10 : ";
    cin >> sizeM;
    int Matrix[sizeM][sizeM];
    for (int i = 0; i < sizeM; ++i)
    {
        for (int j = 0; j < sizeM; ++j)
            cin >> Matrix[i][j];
    }
    for (int i = 0, c = sizeM - 1; c >= 0; ++i, c--)
    {
        for (int j = 0; j < sizeM; ++j)
        {
            columnSum += Matrix[j][i];
            rowSum += Matrix[i][j];
        }
        cout << "The sum of the elemnts of row " << rcNum << " is " << rowSum << endl;
        cout << "The sum of the elemnts of column " << rcNum << " is " << columnSum << endl;
        rowSum = 0;
        columnSum = 0;
        rcNum++;
        mainSum += Matrix[i][i];
        counterSum += Matrix[i][c];
    }
    cout << "The sum of the elemnts of the main diagonal is " << mainSum << endl;
    cout << "The sum of the elemnts of the counter diagonal is " << counterSum << endl;
}

void transpose()
{
    int row, column;
    cout << "Enter the number of rows and columuns :\n"
         << setw(10) << "row : ";
    cin >> row;
    cout << setw(10) << "column : ";
    cin >> column;
    int Matrix[row][column], Transpose[column][row];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            cin >> Matrix[i][j];
            Transpose[j][i] = Matrix[i][j];
        }
    }
    for (auto &c : Transpose)
    {
        for (auto &r : c)
            cout << r << " ";
        cout << endl;
    }
}

void arRay()
{
    int arr[5] = {1, 2, 4, 2, 3};

    for (int j = 0; j <= 6; ++j)
        cout << arr[j] << ' ';
    cout << endl;
}

void bill()
{
    int Q1, Q2, Q3, Q4, Q5;
    float totalTV, totalVCR, totalRC, totalCD, totalTR, subTotal, tax, total;
    cout << setw(40) << "The quantity of TV sold :";
    cin >> Q1;
    cout << setw(40) << "The quantity of VCR sold :";
    cin >> Q2;
    cout << setw(40) << "The quantity of Remote Controller sold :";
    cin >> Q3;
    cout << setw(40) << "The quantity of CD player sold :";
    cin >> Q4;
    cout << setw(40) << "The quantity of Tape Recorder sold :";
    cin >> Q5;

    totalTV = Q1 * 400;
    totalVCR = Q2 * 220;
    totalRC = Q5 * 35.20;
    totalCD = Q4 * 300;
    totalTR = Q5 * 150;

    subTotal = totalTV + totalVCR + totalRC + totalCD + totalTR;
    tax = (8.25 / 100) * subTotal;
    total = subTotal + tax;

    cout << "\nQTY\tDESCRIPTION   \tUNIT PRICE($)\tTOTAL PRICE($)\n";
    cout << "___\t_____________ \t____________ \t    _________\n";
    cout << Q1 << setw(20) << "TV" << setw(15) << "400.00" << setw(15) << totalTV << endl;
    cout << Q2 << setw(20) << "VCR" << setw(15) << "220.00" << setw(15) << totalVCR << endl;
    cout << Q3 << setw(20) << "REMOTE CTRLR" << setw(15) << "35.20" << setw(15) << totalRC << endl;
    cout << Q4 << setw(20) << "CD PLAYER" << setw(15) << "300.00" << setw(15) << totalCD << endl;
    cout << Q5 << setw(20) << "TAPE RECORDER" << setw(15) << "150.00" << setw(15) << totalTR << endl
         << endl;
    cout << setw(21) << "SUBTOTAL" << setw(15) << subTotal << endl;
    cout << setw(21) << "TAX" << setw(15) << tax << endl;
    cout << setw(21) << "TOTAL" << setw(15) << total << endl;
}
void time()
{
    int seconds, hour, minute, second;
    cout << "enter the number of seconds : ";
    cin >> seconds;
    hour = seconds / 3600;
    minute = (seconds % 3600) / 60;
    second = (seconds % 3600) % 60;
    cout << hour << " : " << minute << " : " << second;
}

void number()
{
    string num;
    cout << "enter a number : ";
    cin >> num;
    for (int i = 0; i < num.size(); ++i)
    {
        for (int j = 0; j < num.size(); ++j)
        {
            if (j >= i)
                cout << num[j] << "  ";
            else
                cout << 0 << "  ";
        }
        cout << endl;
    }
}

void quadEquation()
{
    float a, b, c, res1, res2;
    cout << "To solve a quadratic equation\nenter a: ";//ax2 + bx + c
    cin >> a;
    cout << "enter b: ";
    cin >> b;
    cout << "enter c: ";
    cin >> c;
    if (((b * b) - (4 * a * c)) < 0)
        error("no solution!");
    res1 = (-b + sqrt(b * b - (4 * a * c))) / (2 * a);
    res2 = (-b - sqrt(b * b - (4 * a * c))) / (2 * a);
    cout << "The solution set is {" << res1 << ", " << res2 << "}";
}
void numsum()
{
    vector<float> nums;
    float num, sum = 0;
    int n;
    cout << "Please enter the number of values you want to sum: ";
    cin >> n;
    while (cin >> num)
        nums.push_back(num);
    if (n > nums.size())
        error("not enough numbers");
    for (int i = 0; i < n; ++i)
        sum += nums[i];
    cout << "The sum of the first " << n << " numbers (";
    for (int j = 0; j < n; ++j)
        cout << nums[j] << ", ";
    cout << ") is " << sum;
}
void grade()
{
    float grade_A_plus = 0, grade_A = 0, grade_A_minus = 0, grade_B_plus = 0,
          grade_B = 0, grade_B_minus = 0, grade_C_plus = 0, grade_C = 0,
          grade_C_minus = 0, grade_D = 0, grade_F = 0;
    float score;
    bool end = false;
    while (!end)
    {
        cin >> score;
        if (score < 0 || score > 100)
            end = true;
        else
        {
            if (score >= 90)
                grade_A_plus += 1;
            else if (score >= 85 && score < 90)
                grade_A += 1;
            else if (score >= 80 && score < 85)
                grade_A_minus += 1;
            else if (score >= 75 && score < 80)
                grade_B_plus += 1;
            else if (score >= 68 && score < 75)
                grade_B += 1;
            else if (score >= 65 && score < 68)
                grade_B_minus += 1;
            else if (score >= 60 && score < 65)
                grade_C_plus += 1;
            else if (score >= 50 && score < 60)
                grade_C += 1;
            else if (score >= 45 && score < 50)
                grade_C_minus += 1;
            else if (score >= 40 && score < 45)
                grade_D += 1;
            else
                grade_F += 1;
            cout << score << " ";
        }
    }
    cout << "\nNumber of students who scored 'A+' is " << grade_A_plus << endl;
    cout << "Number of students who scored 'A' is " << grade_A << endl;
    cout << "Number of students who scored 'A-' is " << grade_A_minus << endl;
    cout << "Number of students who scored 'B+' is " << grade_B_plus << endl;
    cout << "Number of students who scored 'B' is " << grade_B << endl;
    cout << "Number of students who scored 'B-' is " << grade_B_minus << endl;
    cout << "Number of students who scored 'C+' is " << grade_C_plus << endl;
    cout << "Number of students who scored 'C' is " << grade_C << endl;
    cout << "Number of students who scored 'C-' is " << grade_C_minus << endl;
    cout << "Number of students who scored 'D' is " << grade_D << endl;
    cout << "Number of students who scored 'F' is " << grade_F << endl;
}

void quad()
{
    int y, r;
    cout << "\nenter the length of the quadrilateral you want to print(it must not surpass 60): \n";
    cin >> y;
    cout << "enter the width of the quadrilateral you want to print(it must not surpass 60): \n";
    cin >> r;
    if (r > 0)
    {
        for (int x = 1; x <= y; ++x)
        {
            cout << "A ";
        }
    }
    cout << endl;
    for (int z = 1; z <= r - 2; ++z)
    {
        for (int x = 1; x <= y; ++x)
        {
            if (x == 1 || x == y)
                cout << "A ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    if (r > 1)
    {
        for (int x = 1; x <= y; ++x)
        {
            cout << "A ";
        }
    }
}
void numstar()
{
    int n;
    cout << "enter the number : ";
    cin >> n;
    for (int s = 1; s <= n; ++s)
    {
        for (int d = 1; d <= n; ++d)
        {
            if (d <= s)
                cout << d << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}
void invert()
{
    cout << "enter a number to invert: \n";
    string number;
    cin >> number;
    for (int i = number.size(); i >= 0; --i)
    {
        cout << number[i];
    }
}
void quadrant()
{
    float x;
    cout << "\nenter the value of degree to know its quadrant: \n";
    cin >> x;
    if (x > 0)
    {
        while (x > 360)
            x -= 360;
    }
    else
    {
        while (x < -360)
            x += 360;
    }

    if (x == 0 || x == 360 || x == -360)
        cout << "The degree you entered is on the positive x-axis!\n";
    else if (x == 90 || x == -270)
        cout << "The degree you entered is on the positive y-axis!\n";
    else if (x == 270 || x == -90)
        cout << "The degree you entered is on the negative y-axis!\n";
    else if (x == 180 || x == -180)
        cout << "The degree you entered is on the negative x-axis!\n";
    else if ((x > 0 && x < 90) || (x > -360 && x < -270))
        cout << "The degree you entered is on the first quadrant!\n";
    else if ((x > 90 && x < 180) || (x > -270 && x < -180))
        cout << "The degree you entered is on the second quadrant!\n";
    else if ((x > 180 && x < 270) || (x > -180 && x < -90))
        cout << "The degree you entered is on the third quadrant!\n";
    else if ((x > 270 && x < 360) || (x > -90 && x < 0))
        cout << "The degree you entered is on the fourth quadrant!\n";
    else
        cout << "ooooooops!\n";
}
void mode()
{
    float nums;
    vector<float> modeNum, num;
    vector<int> rept;
    bool enough = false;
    while (cin >> nums) // ctrl + Z + enter to stop entering numbers
        num.push_back(nums);
    sort(num.begin(), num.end());
    int q = 0;
    for (int e = 0; e < num.size(); ++e)
    {
        if (e == 0)
        {
            q++;
            rept.push_back(e);
            modeNum.push_back(e);
        }
        else if (e == num.size() - 1)
        {
            if (num[e] == num[e - 1])
            {
                if (q + 1 > rept[rept.size() - 1])
                {
                    for (int i = 0; i < rept.size(); ++i)
                    {
                        rept.pop_back();
                        modeNum.pop_back();
                    }
                    rept.push_back(q + 1);
                    modeNum.push_back(num[e]);
                }
                else if (q + 1 == rept[rept.size() - 1])
                {
                    rept.push_back(q + 1);
                    modeNum.push_back(num[e]);
                }
                else
                {
                }
            }
            else if (num[e] != num[e - 1])
            {
                if (q > rept[rept.size() - 1])
                {
                    for (int i = 0; i < rept.size(); ++i)
                    {
                        rept.pop_back();
                        modeNum.pop_back();
                    }
                    rept.push_back(q);
                    modeNum.push_back(num[e - 1]);
                }
                else if (q == rept[rept.size() - 1])
                {
                    rept.push_back(q);
                    modeNum.push_back(num[e - 1]);
                }
                else
                {
                }
                if (1 == rept[rept.size() - 1])
                {
                    rept.push_back(q);
                    modeNum.push_back(num[e]);
                }
            }
            else
            {
            }
        }
        else if (num[e] != num[e - 1])
        {
            if (q > rept[rept.size() - 1])
            {
                for (int i = 0; i < rept.size(); ++i)
                {
                    rept.pop_back();
                    modeNum.pop_back();
                }
                rept.push_back(q);
                modeNum.push_back(num[e - 1]);
            }
            else if (q == rept[rept.size() - 1])
            {
                rept.push_back(q);
                modeNum.push_back(num[e - 1]);
            }
            else
            {
            }
            q = 1;
        }
        else
        {
            q++;
        }
    }
    for (int r = 0; r < rept.size(); ++r)
    {
        cout << modeNum[r] << " is a mode number with a repetition of " << rept[r] << " times.\n";
    }
}

void mode2()
{
    vector<int> numbers, modeNumbers{0}, repetition{0};
    int num;
    ifstream ist{"mydata.txt"};
    while (ist >> num)
        numbers.push_back(num);
    sort(numbers.begin(), numbers.end());
    int reptCount = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i == 0)
        {
            reptCount++;
            continue;
        }
        else if (i == numbers.size() - 1)
        {

            if (numbers[i] != numbers[i - 1])
            {
                make_mode(numbers[i - 1], reptCount, modeNumbers, repetition);
                reptCount = 1;
                make_mode(numbers[i], reptCount, modeNumbers, repetition);
            }
            else
            {
                reptCount++;
                make_mode(numbers[i], reptCount, modeNumbers, repetition);
            }
            continue;
        }
        else if (numbers[i] != numbers[i - 1])
            make_mode(numbers[i - 1], reptCount, modeNumbers, repetition);
        else
            reptCount++;
    }
    for (int j = 0; j < modeNumbers.size(); ++j)
        cout << "(" << modeNumbers[j] << ", " << repetition[j] << ")\n";
}

void make_mode(int &num, int &count, vector<int> &mode, vector<int> &rept)
{
    if (count > rept[0])
    {
        for (int i = mode.size() - 1; i >= 0; i--)
        {
            rept.pop_back();
            mode.pop_back();
        }
        mode.push_back(num);
        rept.push_back(count);
        count = 1;
    }
    else if (count == rept[0])
    {
        mode.push_back(num);
        rept.push_back(count);
        count = 1;
    }
    else
        count = 1;
}

// if(reptCount > repetition[0])
//             {
//                 for(int i=0;i<repetition.size();++i)
//                 {
//                     repetition.pop_back();
//                     modeNumbers.pop_back();
//                 }
//                 modeNumbers.push_back(numbers[i-1]);
//                 repetition.push_back(reptCount);
//                 reptCount = 0;
//             }
//             else if(reptCount == repetition[0])
//             {
//                 modeNumbers.push_back(numbers[i-1]);
//                 repetition.push_back(reptCount);
//             }
//             else ;