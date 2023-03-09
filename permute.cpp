#include"std_lib.cpp"

using namespace std;
void triangle();
void work();
int getnumber();
long long permutation(int a, int b), combination(int a, int b), fatorial(int a);


int main()
{
    work();
    return 0;
}

void work()
{
    int a, b;
    char choice;
    cout<<"Enter two numbers!\nnumber 1 : ";
    a = getnumber();
    cout<<"number 2 : ";
    b = getnumber();
    cout<<"What do you want to do?\nA) permutation \t B) combination?\n\tAnswer : ";
    cin>>choice;
    switch(choice)
    {
        case 'A': case 'a':
            cout<<"The permutation is "<<permutation(a, b);
            break;
        case 'B':case 'b':
            cout<<"The combination is "<<combination(a, b);
            break;
        default:
            cout<<"Error!";
    }
}

int getnumber()
{
    int x;
    cin>>x;
    return x;
}

long long factorial(int a)
{
    long long result = 1;
    if(a < 0)   
        error("negative number");
    if(a == 0)    
        result = 1;
    else
    {
        for(int i = a;i > 0;--i)
            result *= i;
    }
    return result;
}

long long permutation(int a, int b)
{
    long long result;
    result = factorial(a) / factorial(a - b);
    return result;
}

long long combination(int a, int b)
{
    long long result;
    result = permutation(a, b) / factorial(b);
    return result;
}











void triangle()
{
    int y=65;
    for(int i=0;i<=26;++i)
    {
        y=65+i;
        if(i==26)
        {
            y=65;
            for(int z=0;z<26;++z)
            {
                if(z==25 )   cout<<'A';
                else cout<<char(y)<<" ";
                y++;
            }
        }
        else
        {
            for(int j=0;j<52;++j)
            {
                if(j==26-i)
                {
                    cout<<char(y);
                    y++;
                }
                else if(j==26+i)
                {
                    y=91-i;
                    cout<<char(y);
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
}
