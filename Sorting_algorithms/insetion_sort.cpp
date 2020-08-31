#include<iostream>
using namespace std;
int  InsertionSort(int a[], int s)
{
    int i,j,key;
    for(i = 1;i<s;i++)
    {
        key = a[i];
        j = i - 1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
    return 0;
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
    InsertionSort(a,s);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
