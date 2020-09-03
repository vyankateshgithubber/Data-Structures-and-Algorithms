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
string PrefixToPostfix(string prefix)
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
            s.push(op1 + op2 + prefix[i]);
        }
    }
    return s.top();
}
int main()
{
    string postfix, prefix;
    cout<<"Enter a Prefix Expression : "<<endl;
    cin>>prefix;
    cout<<"PREFIX EXPRESSION : "<<prefix<<endl;
    prefix = PrefixToPostfix(prefix);
    cout<<endl<<"POSTFIX EXPRESSION : "<<prefix;
    return 0;
}
