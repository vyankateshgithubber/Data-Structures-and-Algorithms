// implementation of circular linked list
#include<iostream>
using namespace std;

class Node
{
    public:
        int key;
        int data;
        Node* next;
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
    }
};

class CircularlyLinkedList
{
    public:
        Node *head;

        CircularlyLinkedList()
        {
            head = NULL;
        }
        CircularLinkedList(Node *n)
        {
            head = n;
            n->next = n;
        }
        //1. check if node exists using key value

        Node* nodeExists(int k)
        {
            Node *temp = NULL;
            Node *ptr = head;
            if(ptr!=NULL)
            {
                do
                {
                    if(ptr->key==k)
                    {
                        temp = ptr;
                    }
                    ptr = ptr->next;
                }while(ptr!=head);
            }
            return temp;
        }
        // 2. Append a node to the list
        void appendNode(Node *n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node Already exists with key value : "<<n->key<<". Append another node with different key value"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head = n;
                    n->next = n;
                    cout<<"Node Appended at Head"<<endl;
                }
                else
                {
                    Node *ptr = head;
                    while(ptr->next!=head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->next = head;
                    cout<<"Node Appended"<<endl;
                }
            }
        }
        // 3. Prepend Node - Attach  node at start
        void prependNode(Node* n)
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node Already exists with key value : "<<n->key<<". Append another node with different key value"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head = n;
                    n->next = n;
                    cout<<"Node prepended at Head"<<endl;
                }
                else
                {
                    Node *ptr = head;
                    while(ptr->next!=head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->next = head;
                    head = n;
                    cout<<"Node Prepended"<<endl;
                }
            }
        }
        // 4. Insert a Node after a particular node in the list
        void insertNodeAfter(int k,Node *n)
        {
            Node *ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"No node exists with key value: "<<endl;
            }
            else
            {
                if(nodeExists(n->key)!=NULL)
                {
                cout<<"Node Already exists with key value : "<<n->key<<". Append another node with different key value"<<endl;
                }
                else
                {
                    if(ptr->next==head)
                    {
                        n->next = head;
                        ptr->next = n;
                        cout<<"Node inserted"<<endl;
                    }
                    else
                    {
                        n->next = ptr->next;
                        ptr->next = n;
                        cout<<"Node Inserted"<<endl;
                    }
                }
            }
        }
        /// 5. Delete the node by key
        void deleteNodeByKey(int k)
        {
            Node *ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"Key value doesnt exits"<<endl;
            }
            else
            {
                if(head==NULL)
                    cout<<"list is empty"<<endl;
                else if(ptr==head)
                {
                    if(head->next==head)
                    {
                        head = NULL;
                        cout<<"list empty"<<endl;
                    }
                    else
                    {
                        Node *ptr1 = head;
                        while(ptr1->next!=head)
                        {
                            ptr1 = ptr1->next;
                        }
                        ptr1->next = head->next;
                        head = head->next;
                        cout<<"Last Node  is unlinked"<<endl;
                    }
                }
                else
                {
                    Node *temp=NULL;
                    Node *prevptr = head;
                    while(prevptr->next->key!=k)
                    {
                        prevptr = prevptr->next;
                    }
                    temp = prevptr->next;
                    if(temp!=NULL)
                    {
                        prevptr->next = temp->next;
                        cout<<" Node UNLINKED with keys value : "<<k<<endl;
                    }
                    else
                    {
                        cout<<" Node doesn't exist with keys value : "<<k<<endl;
                    }
                }
            }
        }
        // 6 update node
        void updateNodeByKey(int k,int d)
        {
            Node *ptr = nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data = d;
                cout<<"Node Data Updated Successful"<<endl;
            }
            else
            {
                cout<<"Node Doesn't exist with key value : "<<k<<endl;
            }
        }
        // 7 printing
        void printlist()
        {
            if(head==NULL)
            {
                cout<<"No nodes in Singly Linked List";
            }
            else
            {
                cout<<"Singly Linked List Values : "<<endl;
                Node *temp = head;
                do
                {
                    cout<<"("<<temp->key<<","<<temp->data<<") --> ";
                    temp = temp->next;
                }while(temp!=head);
            }
        }
};
int main()
{
    CircularlyLinkedList s;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<"\n What operation do you want to perform? Select Option Number, Enter 0 to exit"<<endl;
        cout<<"1. appendNode"<<endl;
        cout<<"2. prependNode"<<endl;
        cout<<"3. insertNodeAfter"<<endl;
        cout<<"4. deleteNodeByKey"<<endl;
        cout<<"5. updateNodeBYKey"<<endl;
        cout<<"6. print"<<endl;
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
            s.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;

            s.insertNodeAfter(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);

            break;
        case 6:
            s.printlist();

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
