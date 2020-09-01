#include<iostream>
using namespace std;
void  QuickSort(int a[], int left, int right);
int partitions(int a[], int s,int e);

void  QuickSort(int a[], int left, int right)
{
    if(left < right)
    {
        int p = partitions(a,left,right);
        QuickSort(a,left,p-1);
        QuickSort(a,p+1,right);
    }
}

int partitions(int a[], int s,int e)
{
    int pivot = a[e];
    int pIndex = s,tmp;
    for(int i=s;i<(e);i++)
    {
        if(a[i]<=pivot)
        {
            tmp = a[pIndex];
            a[pIndex] = a[i];
            a[i] = tmp;
            pIndex++;
        }
    }
    tmp = a[pIndex];
    a[pIndex] = a[e];
    a[e] = tmp;
    return pIndex;
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
    QuickSort(a,0,s-1);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
