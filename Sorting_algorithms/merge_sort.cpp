#include<iostream>
using namespace std;
void  MergeSort(int a[], int left, int right);
void Merge(int a[], int l,int m, int r);

void  MergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid=(left + right)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        Merge(a,left,mid,right);
    }
}

void Merge(int a[], int l,int m, int r)
{
    int i=l,j=m+1,k=l;
    int tmp[100];
    while(i<=m && j<=r)
    {
        if(a[i]<=a[j])
        {
            tmp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            tmp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        tmp[k]=a[i];
        k++;
        i++;
    }
    while(j<=r)
    {
        tmp[k]=a[j];
        k++;
        j++;
    }
    for(int p=l;p<k;p++)
    {
        a[p]=tmp[p];
    }
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
    MergeSort(a,0,s-1);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
