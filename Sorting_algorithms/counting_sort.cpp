#include<iostream>
using namespace std;
// counting sort algorithm implementation input  range 0 - 9
int CountSort(int a[], int s,int r)
{
    int output_array[s],i;
    int count_array[10];

    for(i=0;i<r;i++)
    {
        count_array[i]=0;
    }
    for(i=0;i<s;i++)
    {
        ++count_array[a[i]];
    }
    for(i=1;i<r;i++)
    {
        count_array[i] = count_array[i] + count_array[i-1];
    }
    for(i=0;i<s;i++)
    {
        output_array[--count_array[a[i]]] = a[i];
    }
    for(i=0;i<s;i++)
    {
        a[i] = output_array[i];
    }
    return 0;
}
int main()
{
    int s,a[100];
    cout<<"Enter the size of array "<<endl;
    cin>>s;
    cout<<"Enter the elements of array in range 0 - 9 "<<endl;
    for(int i=0;i<s;i++)
    {
        cin>>a[i];
    }
    CountSort(a,s);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
