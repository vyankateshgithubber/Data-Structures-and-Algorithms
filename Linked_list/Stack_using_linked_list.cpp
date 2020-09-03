/*
Implementation of stack using linked list
*/
#include<iostream>
using namespace std;


class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k,int d)
    {
        key = k;
        data = d;
        next  = NULL;
    }
};

class Stack
{
    public:
        Node *top;
        Stack()
        {
            top = NULL;
        }
        bool isEmpty()
        {
            if(top==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool checkIfNodeExist(Node *n)
        {
            Node *temp =top;
            bool exists =false;
            while(temp!=NULL)
            {
                if(temp->key==n->key)
                {
                    exists = true;
                    break;
                }
                temp = temp->next;
            }
            return exists;
        }
        void push(Node *n)
        {
            if(top==NULL)
            {
                top = n;
            }
            else if(checkIfNodeExist(n))
            {
                cout<<"Node is already with same key ! Enter the new key"<<endl;
            }
            else
            {
                Node *temp = top;
                top = n;
                n->next = temp;
                cout<<"Pushed "<<endl;
            }
        }
        Node *pop()
        {
            Node *temp = NULL;
            if(isEmpty())
            {
                cout<<"Stack underflow"<<endl;
                return temp;
            }
            else
            {
                temp = top;
                top = top->next;
                return temp;
            }
        }

        Node *peek()
        {
            if(isEmpty())
            {
                cout<<"Stack underflow"<<endl;
                return NULL;
            }
            else
            {
                return top;
            }
        }
        int count()
        {
            int count=0;
            Node *temp =top;
            while(temp!=NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
        void display()
        {

            cout<<"All values in Stack :"<<endl;
            Node *temp=top;
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<")"<<"-->"<<endl;
                temp = temp->next;
            }
        }



};
int main()
{
    Stack s;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<"\n What operation do you want to perform? Select Option Number, Enter 0 to exit"<<endl;
        cout<<"1. Push()"<<endl;
        cout<<"2. Pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. peek()"<<endl;
        cout<<"5. count()"<<endl;
        cout<<"6. display()"<<endl;
        cout<<"7. clear screen"<<endl;
        cin>>option;
        Node *n1 = new Node();//dynamically allocated
        switch(option)
        {
        case 0:
            break;
        case 1:
            cout<<"Enter key and value"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            s.push(n1);
            break;
        case 2:
            cout << "Pop Function Called - Poped Value" << endl;
            n1 = s.pop();
            cout<<"key :"<<n1->key<<"data : "<<n1->data<<endl;
            delete n1;
            break;

        case 3:
            if(s.isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                cout<<"Stack is not empty"<<endl;
            }
            break;
        case 4:
            if(s.isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
            }
            else
            {
                n1 = s.peek();
                cout<<"Peek value : "<<n1->data<<endl;
            }
            break;
        case 5:
            cout <<"Count of number of values :"<<s.count()<< endl;
            break;
        case 6:
            cout<<"Display Function :"<<endl;
            s.display();

            break;
        case 7:
            //system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    }while(option!=0);
return 0;
}

