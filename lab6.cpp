#include <iostream>
#include <iomanip>
#include <fstream>
#include <fcntl.h>
using namespace std;

struct Student
{
    string name;
    unsigned id;
    float marks[5];
    float average;
    unsigned rank;
};
string subject[] = {"Programming 2", "Calculus I", "Linear Algebra", "Digital Electronics", "Statistics"};

string get_subject(int i);
void average_score(Student x[], int size);
void sort(Student arr[], int size);
void rank_calc(Student y[], int size);
void display_student_data(Student x[], int, int);
void accept_student_data(Student list[], int num_of_students);
void search_student(Student z[], int size, int id);
void student_info();

fstream lab{"lab6.txt"};

int main()
{
    student_info();
    return 0;
}

void student_info()
{
    cout << "Enter the number of students to store their data : ";
    int num, search_id;
    lab >> num;
    Student list[num];
    accept_student_data(list, num);
    average_score(list, num);
    rank_calc(list, num);
    display_student_data(list, 0, num);
    // cout << "Enter an ID number to get the student information with that id : ";
    // cin >> search_id;
    // search_student(list, num, search_id);
}

void display_student_data(Student x[], int index1, int index2)
{
    // fstream stdfile{"student_data.txt"};
    cout << "Student Name  Student ID" << setw(15) << " Programming 2" << setw(15) << " Calculus I" << setw(15) << "L. Algebra" << setw(15) << "   D. Electronics" << setw(15) << "Statistics"
         << "  Average"
         << " Rank\n";
    for (int i = index1; i < index2; i++)
    {
        cout << setw(12) << x[i].name << setw(10) << x[i].id;
        for (int j = 0; j < 5; j++)
            cout << setw(14) << x[i].marks[j];
        cout << setprecision(2) << "  " << setw(10) << x[i].average << "\t  " << x[i].rank << endl;
    }
}

void accept_student_data(Student list[], int num_of_students)
{
    Student x;
    for (int i = 0; i < num_of_students; i++)
    {
        cout << "\n**********Student " << i + 1 << " Data**********\n\n"
             << "Full Name : ";
        lab >> x.name;
        cout << "ID No. : ";
        lab >> x.id;
        cout << "\nscore in : \n";
        for (int i = 0; i < 5; i++)
        {
            cout << setw(20) << get_subject(i) << " = ";
            lab >> x.marks[i];
        }
        list[i] = x;
        system("cls");
    }
}

void average_score(Student x[], int size)
{
    for (int j = 0; j < size; j++)
    {
        float sum = 0;
        for (int i = 0; i < 5; i++)
            sum += x[j].marks[i];
        x[j].average = sum / 5.0;
    }
}

void rank_calc(Student y[], int size)
{
    sort(y, size);
    int rank_c = 1;
    y[0].rank = rank_c;
    for (int i = 1; i < size; i++)
    {
        if (y[i].average == y[i - 1].average)
        {
            y[i].rank = y[i - 1].rank;
            rank_c++;
        }
        else
        {
            y[i].rank = rank_c + 1;
            rank_c++;
        }
    }
}

void search_student(Student z[], int size, int id)
{
    for (int i = 0; i < size; i++)
        if (id == z[i].id)
        {
            display_student_data(z, i, i + 1);
            break;
        }
    cout << "Can't find a student with ID " << id << endl;
}

string get_subject(int x)
{
    return subject[x];
}

void sort(Student arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        Student temp;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i].average < arr[j].average)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

