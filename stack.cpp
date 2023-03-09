#include <iostream>
#define MAXSTACK 20
using namespace std;

class node
{
public:
    int value;
    node *next;
    node *prev;
};

class Stack
{
    node *top;
    int s = 0;

public:
    void push(int x)
    {
        node *temp = new node;
        temp->value = x;
        if (s == 0)
        {
            top = temp;
        }
        else
        {
            top->next = temp;
            temp->prev = top;
            top = temp;
        }
        s++;
    }
    int pop()
    {
        int temp;
        if (s == 0)
        {
            cout << "underflow";
            throw exception();
        }
        else
        {
            temp = top->value;
            top = top->prev;
            delete top->next;
            s--;
        }
        return temp;
    }
    int peek()
    {
        if (s == 0)
        {
            cout << "underflow";
            throw exception();
        }
        else
            return top->value;
    }
    bool isEmpty()
    {
        return (s == 0);
    }
    // bool isFull() {

    // }
    int size()
    {
        return s;
    }
};

class stack
{
    int values[MAXSTACK];
    int top = -1;
    // int size = 0;

public:
    void push(int x)
    {
        if (top == MAXSTACK - 1)
            cout << "overflow";
        else
        {
            top++;
            values[top] = x;
        }
    }
    int pop()
    {
        int temp;
        if (top == -1)
        {
            cout << "underflow";
            throw exception();
        }
        else
        {
            temp = values[top];
            top--;
        }
        return temp;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAXSTACK - 1;
    }
    int size()
    {
        return top + 1;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "no value to return";
            throw exception();
        }
        else
        {
            return values[top];
        }
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << st.size() << endl;
    st.pop();
    st.pop();
    cout << st.size() << endl;
    st.pop();
    cout << st.size() << endl;
    st.pop();
    st.pop();
    cout << st.size() << endl;
    st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.isEmpty();
    cout << st.isEmpty();
    return 0;
}