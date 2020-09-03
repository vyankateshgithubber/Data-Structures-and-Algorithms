#include <iostream>

using namespace std;

class Stack{
    private:
        int top;
        int arr[5];


    public:
        Stack()
        {
            top = -1;
            for(int i = 0;i<5;i++)
            {
                arr[i]=0;
            }
        }
        bool isEmpty()
        {
            if(top==-1)
                return true;
            else
                return false;
        }
        bool idFull()
        {
            if(top==4)
                return true;
            else
                return false;
        }
        void push(int val)
        {
            if(idFull())
            {

                cout<<"Stack overflow"<<endl;
            }
            else
            {
                top++;
                arr[top]=val;
            }
        }
        int pop()
        {

            if(isEmpty())
            {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else
            {
                int popvalue = arr[top];
                arr[top] = 0;
                top--;
                return popvalue;
            }
        }
        int count()
        {
            return (top+1);
        }
        int peek(int pos)
        {
            if(isEmpty())
            {
                cout<<"Stack Underflow"<<endl;
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }

        void change(int pos,int val)
        {
            arr[pos]=val;
            cout<<arr[pos]<<endl;
        }
        void display()
        {
            cout<<"Elements"<<endl;
            for(int i=4;i>=0;i--)
                cout<<arr[i]<<endl;
        }
};
int main()
{
    cout << "Hello world!" << endl;
    Stack s1;
    s1.display();
    s1.push(4);
    cout<<s1.peek(0);
    s1.push(5);
    cout<<s1.count();
    cout<<s1.pop();
    return 0;
}
