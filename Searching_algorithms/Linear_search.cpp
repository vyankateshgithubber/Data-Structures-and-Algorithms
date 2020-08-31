#include<iostream>
using namespace std;
int  LinearSearch(int a[], int s)
{
    int n;
    cout<<"Enter the element that to be searched"<<endl;
    cin>>n;
    for(int i=0;i<s;i++)
    {
        if(a[i]==n)
        {
            return i;
        }
    }
    return -1;

}

int main()
{
    int s,a[100];
    cout<<"Enter the size of array "<<endl;
    cin>>s;
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<s;i++)
    {
        cin>>a[i];
    }
    int index = LinearSearch(a,s);
    if(index!=-1)
    {
        cout<<"Element is found at index "<<index<<endl;
    }
    else
    {
        cout<<"Element is not found"<<endl;
    }
}
