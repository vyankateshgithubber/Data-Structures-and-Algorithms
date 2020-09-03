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
string PrefixToInfix(string prefix)
{
    stack<string> s;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        if(!isOperator(prefix[i]))
        {
            string op(1,prefix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}
int main()
{
    string infix, prefix;
    cout<<"Enter a Pretfix Expression : "<<endl;
    cin>>prefix;
    cout<<"PREFIX EXPRESSION : "<<prefix<<endl;
    infix = PrefixToInfix(prefix);
    cout<<endl<<"INFIX EXPRESSION : "<<infix;
    return 0;
}
