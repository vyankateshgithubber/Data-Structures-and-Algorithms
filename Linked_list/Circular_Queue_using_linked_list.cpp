/*
Implementation of circular queue using linked list
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

class CQueue
{
    public:
        Node *front;
        Node *rear;
        Queue()
        {
            front = NULL;
            rear = NULL;
        }
        bool isEmpty()
        {
            if(front==NULL && rear==NULL)
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
            Node *temp =front;
            bool exists =false;
            do
            {
                if(temp->key==n->key)
                {
                    exists = true;
                    break;
                }
                temp = temp->next;
            }while(temp!=rear);
            return exists;
        }
        void enqueue(Node *n)
        {
            if(front==NULL && rear==NULL)
            {
                front = n;
                rear = n;
                cout<<"Enqueued"<<endl;
            }
            else if(checkIfNodeExist(n))
            {
                cout<<"Node is already with same key ! Enter the new key"<<endl;
            }
            else
            {
                rear->next=n;
                rear=n;
                n->next=front;
                cout<<"Enqueued "<<endl;
            }
        }
        Node *dequeue()
        {
            Node *temp = NULL;
            if(isEmpty())
            {
                cout<<"Queue underflow"<<endl;
                return temp;
            }
            else
            {
                if(front==rear)
                {
                    temp = front;
                    front = NULL;
                    rear = NULL;
                    return temp;
                }
                else
                {
                    temp = front;
                    front = front->next;
                    rear->next = front;
                    return temp;
                }
            }
        }

        Node *peek()
        {
            if(isEmpty())
            {
                cout<<"Queue underflow"<<endl;
                return NULL;
            }
            else
            {
                return front;
            }
        }
        int count()
        {
            int count=0;
            Node *temp =front;
            do
            {
                count++;
                temp = temp->next;
            }while(temp!=front);
            return count;
        }
        void display()
        {

            cout<<"All values in Stack :"<<endl;
            Node *temp=front;
            do
            {
                cout<<"("<<temp->key<<","<<temp->data<<")"<<"-->"<<endl;
                temp = temp->next;
            }while(temp!=front);
          }
};
int main()
{
    CQueue s;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<"\n What operation do you want to perform? Select Option Number, Enter 0 to exit"<<endl;
        cout<<"1. Enqueue()"<<endl;
        cout<<"2. Dequeue()"<<endl;
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
            s.enqueue(n1);
            break;
        case 2:
            cout << "Dequeued Function Called - Dequeue Value" << endl;
            n1 = s.dequeue();
            cout<<"key :"<<n1->key<<"data : "<<n1->data<<endl;
            delete n1;
            break;

        case 3:
            if(s.isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
            }
            else
            {
                cout<<"Queue is not empty"<<endl;
            }
            break;
        case 4:
            if(s.isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
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

