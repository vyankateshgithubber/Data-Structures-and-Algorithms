#include<iostream>
using namespace std;
class Node{
    public:
        int key;
        int data;
        Node *next;
        Node *previous;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
            previous = NULL;
        }
        Node(int k,int d)
        {
            key = k;
            data = d;
            next = NULL;
            previous = NULL;
        }
};

class DoublyLinkedList{
    public:
        Node* head;

        DoublyLinkedList()
        {
            head = NULL;
        }
        DoublyLinkedList(Node *n)
        {
            head = n;
        }
        // check if node exists
        Node* nodeExists(int k)
        {

            Node *temp = NULL;
            Node *ptr = head;
            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        // Append  the node to list
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
                    cout <<"Noded appended as HEAD"<<endl;
                }
                else
                {
                    Node *ptr = head;
                    while(ptr->next!=NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->previous = ptr;
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
                    cout <<"Noded appended as HEAD"<<endl;
                }
                else
                {
                    head->previous = n;
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
                Node *nextNode = ptr->next;
                //inserting at end
                if(nextNode==NULL)
                {
                    ptr->next=n;
                    n->previous=ptr;
                    cout<<"Node Inserted at end"<<endl;
                }
                else
                {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                    cout<<"Node Inserted"<<endl;
                }
            }
        }
    }
    /// 5. Delete the node by key
    void deleteNodeByKey(int k)
    {
        if(head==NULL)
        {
            cout<<"Singly Linked lists already Empty. can't delete"<<endl;
        }
        else if(head!=NULL)
        {
            if(head->key==k)
            {
                head = head->next;
                cout<<"Node UNLINKED with keys value : "<<k<<endl;
            }
            else
            {
                Node *ptr = nodeExists(k);

                if(ptr!=NULL)
                {
                    Node *nextNode = ptr->next;
                    Node *prevNode = ptr->previous;
                    if(nextNode==NULL)
                    {
                        prevNode->next = NULL;
                        cout<<"Node deleted at end "<<endl;
                    }
                    else
                    {
                        prevNode->next = nextNode;
                        nextNode->previous = prevNode;
                        cout<<"Node Deleted in Between"<<endl;
                    }
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
            cout<<"No nodes in Doubly Linked List";
        }
        else
        {
            cout<<"Doubly Linked List Values : "<<endl;
            Node *temp = head;
            while(temp!=NULL)
            {
                cout<<"("<<temp->key<<","<<temp->data<<") <--> ";
                temp = temp->next;
            }
        }
    }
};


int main()
{
    DoublyLinkedList s;
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
