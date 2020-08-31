#include<iostream>
using namespace std;
int  BinarySearch(int a[], int left, int right, int n)
{
    int mid;
    while(left<=right)
    {
        mid = left+(right-left)/2;
        if(a[mid]==n)
        {
            return mid;
        }
        else if(a[mid]<n)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int s,a[100];
    cout<<"Enter the size of array "<<endl;
    cin>>s;
    cout<<"Enter the elements of array in Acsending Order "<<endl;
    for(int i=0;i<s;i++)
    {
        cin>>a[i];
    }
    int n;
    cout<<"Enter the element that to be searched"<<endl;
    cin>>n;
    int index = BinarySearch(a,0,s-1,n);
    if(index!=-1)
    {
        cout<<"Element is found at index "<<index<<endl;
    }
    else
    {
        cout<<"Element is not found"<<endl;
    }
}
