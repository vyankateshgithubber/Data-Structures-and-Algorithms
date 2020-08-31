#include<iostream>
using namespace std;
int  SelectionSort(int a[], int s)
{
    int min_index,tmp;
    for(int i=0;i<(s-1);i++)
    {
        min_index = i;
        for(int j=i+1;j<s;j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if(min_index!=i)
        {
            tmp = a[min_index];
            a[min_index] = a[i];
            a[i] = tmp;
        }
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
    SelectionSort(a,s);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
