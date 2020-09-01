#include<iostream>
using namespace std;
// counting sort algorithm implementation input  range 0 - 9
int CountingSort(int a[], int s,int div)
{
    int output_array[s],i,r=10;
    int count_array[10];
    for(i=0;i<r;i++)
    {
        count_array[i]=0;
    }
    for(i=0;i<s;i++)
    {
        count_array[(a[i]/div)%10]++;
    }
    for(i=1;i<r;i++)
    {
        count_array[i] = count_array[i] + count_array[i-1];
    }
    for(i=0;i<s;i++)
    {
        output_array[count_array[(a[i]/div)%10]-1] = a[i];
    }
    for(i=0;i<s;i++)
    {
        a[i] = output_array[i];
    }
    return 0;
}
int GetMax(int a[],int s)
{
    int m = a[0];
    for(int i=1;i<s;i++)
    {
        if(a[i]>m)
        {
            m = a[i];
        }
    }
    return m;
}
void RadixSort(int a[],int s)
{
    int m = GetMax(a,s);
    for(int div = 1;m/div>0;div*=10)
    {
        CountingSort(a,s,div);
    }
}
int main()
{
    int s,a[100];
    cout<<"Enter the size of array "<<endl;
    cin>>s;
    cout<<"Enter the elements of array "<<endl;
    for(int i=0;i<s;i++)
    {
        cin>>a[i];
    }
    RadixSort(a,s);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
