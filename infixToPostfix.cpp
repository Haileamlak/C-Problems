// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;

// bool precedence(char op1, char op2);

// string infixToPostfix(string expression)
// {
//     stack<char> operators;
//     string result = "";
//     char item;
//     char x;
//     for (size_t i = 0; i < expression.size(); i++)
//     {
//         item = expression[i];
//         if (isalnum(item))
//         {
//             result.push_back(item);
//             cout << "a" << endl;
//         }
//         else if (item == '(' || item=='^')
//         {
//             operators.push(item);

//             cout << "(" << endl;
//         }
//         else if (item == ')')
//         {
//             while (!operators.empty()&& operators.top() != '(')
//             {

                
//                     x = operators.top();
//                     operators.pop();
                
//                 result.push_back(x);
//             }
            
//         }
//         else
//         {
//             cout << "+-*/" << endl;
//             // if (!operators.empty())
//             while (!operators.empty() && precedence(operators.top(), item))
//             {
//                 x = operators.top();
//                 operators.pop();
//                 result.push_back(x);
//             }
//             operators.push(item);
//         }
//     }

//     while (!operators.empty())
//     {
//         x = operators.top();
//         operators.pop();
//         result.push_back(x);
//     }
//     return result;
// }

// bool precedence(char op1, char op2)
// {
//     if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
//     {
//         return false;
//     }
//     else if ((op1 == '*' || op1 == '/') && (op2 == '-' || op2 == '+'))
//     {
//         return true;
//     }
//     else if ((op1 == '*' || op1 == '/') && (op2 == '/' || op2 == '*'))
//     {
//         return true;
//     }
//     else if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))
//     {
//         return true;
//     }
//     return true;
// }

// int main()
// {
//     cout << infixToPostfix("a/b*(c+(d-e))");
//     return 0;
// }

#include<iostream>
#include<stack>
#include<locale>      //for function isalnum()
using namespace std;

int preced(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;              //Precedence of + or - is 1
   }else if(ch == '*' || ch == '/') {
      return 2;            //Precedence of * or / is 2
   }else if(ch == '^') {
      return 3;            //Precedence of ^ is 3
   }else {
      return 0;
   }
}

string inToPost(string infix ) {
   stack<char> stk;
   stk.push('#');               //add some extra character to avoid underflow
   string postfix = "";         //initially the postfix string is empty
   string::iterator it;

   for(it = infix.begin(); it!=infix.end(); it++) {
      if(isalnum(char(*it)))
         postfix += *it;      //add to postfix when character is letter or number
      else if(*it == '(')
         stk.push('(');
      else if(*it == '^')
         stk.push('^');
      else if(*it == ')') {
         while(stk.top() != '#' && stk.top() != '(') {
            postfix += stk.top(); //store and pop until ( has found
            stk.pop();
         }
         stk.pop();          //remove the '(' from stack
      }else {
         if(preced(*it) > preced(stk.top()))
            stk.push(*it); //push if precedence is high
         else {
            while(stk.top() != '#' && preced(*it) <= preced(stk.top())) {
               postfix += stk.top();        //store and pop until higher precedence is found
               stk.pop();
            }
            stk.push(*it);
         }
      }
   }

   while(stk.top() != '#') {
      postfix += stk.top();        //store and pop until stack is not empty.
      stk.pop();
   }

   return postfix;
}

int main() {
   string infix = "x^y/(5*z)+2";
   cout << "Postfix Form Is: " << inToPost(infix) << endl;
}