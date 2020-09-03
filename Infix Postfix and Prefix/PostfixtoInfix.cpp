#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' ||c=='/'||c=='^')
    {
        return true;
    }
    return false;
}
string PostfixToInfix(string postfix)
{
    stack<string> s;
    for(int i=0;i<postfix.length();i++)
    {
        if(!isOperator(postfix[i]))
        {
            string op(1,postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }
    return s.top();
}
int main()
{
    string infix, postfix;
    cout<<"Enter a Postfix Expression : "<<endl;
    cin>>postfix;
    cout<<"POSTFIX EXPRESSION : "<<postfix<<endl;
    infix = PostfixToInfix(postfix);
    cout<<endl<<"INFIX EXPRESSION : "<<infix;
    return 0;
}
