/*


//          ADDIS ABABA UNIVERSITYENCES
        computer science section 1 Group 8
        Computer Programming Group Assignmen
    COLLEGE OF NATURAL AND COMPUTATIONAL SCIt

    Group members                       ID No.
1. Addisu Seteye .................UGR/0073/13
2. Asmare Zelalem ................UGR/1874/13
3. Awoke Dejenie .................UGR/1146/13
4. Abebe Megibar .................UGR/3819/13
5. Abrham Belayneh ...............UGR/3584/13
6. Helina Bikes ..................UGR/1490/13
7. Birtukan Addis ................UGR/5759/13
8. Dawit Abrham ..................UGR/9329/13
9. Daniel Yirdaw .................UGR/3295/13
10. Haileamlak Belachew ..........UGR/4204/13

                                    Submitted to: Instructor Solomon
                                    Submission date:  Jan 17, 2022


*/

#include <iostream>
#include <iomanip>

using namespace std;

void weekly_ave_temp(), transpose(), inverseArray(), sort(); // declaring functions
float F_to_C(float f), K_to_C(float k);

int main()
{
    char answer;
    cout << "\t\tWelcome to our program!\n";
    while (true)
    {
        cout << "\n\tWhat do you want to do?\n";
        cout << "A) Program 1 calculates the weekly average temperature by receiving the temperature of each day (in celsius scale)!\n";
        cout << "B) Program 2 reverses the order of a list of elements!\n";
        cout << "C) Program 3 transposes any square matrix!\n";
        cout << "D) Program 4 merges and sorts two sorted lists together!\n";
        cout << "\t\t\tenter 'q' to quit!\n";
    there:
        cout << setw(20) << "Answer : ";
        cin >> answer;
        switch (answer)
        {
        case 'A':
        case 'a':
            weekly_ave_temp();
            break;
        case 'B':
        case 'b':
            inverseArray();
            break;
        case 'C':
        case 'c':
            transpose();
            break;
        case 'D':
        case 'd':
            sort();
            break;
        case 'Q':
        case 'q':
            goto under;
            break;
        default:
            cout << "Please enter a valid answer!\n";
            goto there;
        }
        cout << endl;
    }
    cout << endl;
under:
    cout << "\n\t\tThank you!";
    return 0;
}

void weekly_ave_temp()
{
    float temp, daily_temp, sum_temp, ave_temp, weekly_temp[7]; // declaring necessary variables and arrays
    char Tscale;
    cout << "\nEnter the temperature of each day with their scale below!\n";
    for (int i = 0; i < 7; ++i)
    {
        cout << "\nTemperature 0f day " << i + 1 << " = "; //
        cin >> temp >> Tscale;                             // receives the daily temperature
        switch (Tscale)
        {
        case 'F':
        case 'f':
            daily_temp = F_to_C(temp); // changing to celsius scale if the temperature is in fahrenheit scale
            break;
        case 'K':
        case 'k':
            daily_temp = K_to_C(temp); // changing to celsius scale if the temperature is in kelvin scale
            break;
        case 'C':
        case 'c':
        {
            if (temp < 0 || temp > 100)
            {
                cerr << "temperature expexted!";
                exit(0);
            }
            daily_temp = temp;
            break;
        }
        }
        weekly_temp[i] = daily_temp; // storing on an array
    }
    for (int i = 0; i < 7; ++i)     //
        sum_temp += weekly_temp[i]; // summing up the daily temperatures together
    ave_temp = sum_temp / 7;        // calculating the weekly average temperature
    cout << "\nThe weekly average temperature is " << setprecision(4) << ave_temp << " C";
}

void inverseArray()
{
    int n, x;
    cout << "enter the number of elements that you want to reverse their order : ";
    cin >> n;
    int temp, arr[n];
    cout << "Please enter the numbers below!\n";
    for (int i = 0; i < n; ++i) //
        cin >> arr[i];          // receiving each element
    n--;                        // decreement of 'n' since index starts from 0
    for (int i = 0, x = n / 2; i <= x; ++i)
    {
        temp = arr[i];       //
        arr[i] = arr[n - i]; // swapping an element in the first half-
        arr[n - i] = temp;   // with its symmetrical element in the second half
    }
    cout << "The reversed list of the elemnts is shown below!\n"; //
    for (int element : arr)
        cout << element << " "; // printing out the elements using range based for loop
}

void transpose()
{
    int mSize;
    cout << "Enter the size of your matrix to be transposed : ";
    cin >> mSize;
    int Matrix[mSize][mSize], Transpose[mSize][mSize]; // declaring the matrix to be transposed and its transpose

    for (int i = 0; i < mSize; ++i)
    {
        for (int j = 0; j < mSize; ++j)
            cin >> Matrix[i][j]; // receiving the elements of the matrix
    }
    for (int i = 0; i < mSize; ++i)
    {
        for (int j = 0; j < mSize; ++j)
            Transpose[j][i] = Matrix[i][j]; // transposing the the matrix using another array
    }
    cout << "\nThe transpose of your matrix is shown below \n";
    for (auto &c : Transpose)
    {                         //
        for (auto &r : c)     // printing out the transpose of the matrix
            cout << r << " "; // using range based for loop
        cout << endl;         //
    }
}

void sort()
{
    int c = 0, rept = 0, r = 0, n, temp;
    bool repetted = false;
    int array1[11] = {2, 2, 3, 4, 5, 11, 12, 15, 17, 28, 39};              // initializing the first sorted array
    int array2[15] = {0, 1, 1, 6, 7, 8, 8, 9, 14, 19, 34, 37, 38, 38, 40}; // initializing the second sorted array
    int arrMerged[26], sorted[26];
    ; // declaring two array which help to merge and sort the elements
    for (int i = 0, j = 0; i < 26; ++i, j++)
    { //
        if (i == 11)
            j = 0; //
        if (i <= 10)
            arrMerged[i] = array1[j]; // merging the elements together
        else
            arrMerged[i] = array2[j]; //
    }
    for (int i = 0; i < 26; ++i)
    {

        for (int j = 0; j < 26; ++j)
        {
            if (arrMerged[i] == rept && repetted) // checking if the element is a repetted element
                continue;
            if (arrMerged[i] == arrMerged[j])
                r++; // counts the frequency of the element
            if (arrMerged[i] >= arrMerged[j])
                c++; // counts how many elements each element exceeds or equals
            else
                ;
        }
        if (r == 1)
            sorted[c - r] = arrMerged[i]; // sorting the elements based on their level
        else if (r > 1)                   // checks whether or not the element appears more than one times
        {
            for (int x = 1; x <= r; ++x)      //
                sorted[c - x] = arrMerged[i]; // storing repeated elements continuously
            rept = arrMerged[i];              //
            repetted = true;                  //
        }
        else
            ;
        c = 0;
        r = 0;
    }
    cout << "The sorted list of the two sorted lists together is shown below.\n";
    for (int y : sorted)
        cout << y << ", "; // prints the sorted list
}

float K_to_C(float k) // converts kelvin to celsius
{
    if (k < 273 || k > 373)
    {
        cerr << "error : temperature expected";
        exit(0);
    }

    float c = k - 273.15;
    return c;
}
float F_to_C(float f) // converts kelvin to celsius
{
    if (f < 32 || f > 212)
    {
        cerr << "error : temperature expected";
        exit(1);
    }
    float c = (5.0 / 9.0) * (f - 32);
    return c;
}
