#include <iostream>

using namespace std;


class CQueue{
    private:
        int front;
        int rear;
        int arr[5];

    public:
        CQueue()
        {
            int itemcount = 0;
            front = -1;
            rear = -1;
            for(int i=0;i<5;i++)
            {
                arr[i]=0;

            }
        }

        bool isEmpty()
        {
            if(front==-1 && rear==-1)
                return true;
            else
                return false;
        }
        bool isFull()
        {
            if((rear+1)%5 == fornt)
                return true;
            else
                return false;
        }
        void enqueue(int val)
        {
            if(isFull())
                return;
            else if(isEmpty())
            {
                rear = 0;
                front = 0;
                arr[rear] = val;

            }
            else
            {
                rear = (rear + 1)%5;
                arr[rear]=val;
            }
            itemcount++;
        }
        int dequeue()
        {
            int x;
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return 0;

            }
            else if(front == rear)
            {
                x = arr[front];
                arr[front]=0;
                rear = -1;
                front = -1;
                return x;
            }
            else
            {
                x = arr[front];
                arr[front] = 0;
                front = (front+1)%5;
                return x;
            }
            itemcount--;

        }
        int count()
        {
            return itemcount;
        }
        void display()
        {
            cout<<"All values"<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<arr[i]<<" ";
            }
        }


};
int main()
{
    int option;
    int value;
    CQueue q1;
    do
    {
        cout<<"n What optration domyou want to perform, Enter 0 to exit"<<endl;
        cout<<"1.Enqueue()"<<endl;
        cout<<"2.Dequeue()"<<endl;
        cout<<"3.isEmpty()"<<endl;
        cout<<"4.isFull()"<<endl;
        cout<<"5.count()"<<endl;
        cout<<"6.display"<<endl;
        cout<<"7.Clear Screen"<<endl;
    cin>>option;
    switch(option)
    {
    case 0:
        break;
    case 1:
        cin>>value;
        q1.enqueue(value);
        break;
    case 2:
        cout<<q1.dequeue()<<endl;
        break;
    case 3:
        cout<<q1.isEmpty()<<endl;
        break;
    case 4:
        cout<<q1.isFull()<<endl;
        break;
    case 5:
        cout<<q1.count()<<endl;
        break;
    case 6:
        q1.display();
        break;
    case 7:
        //system("cls");
        break;
    default:
        cout<<"Enter another option"<<endl;
        break;
    }
    }while(option!=0);
    return 0;
}
