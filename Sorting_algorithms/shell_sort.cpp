#include<iostream>
using namespace std;
// shell sort algorithm implementation input  range 0 - 9
int ShellSort(int a[], int s)
{
    int gap;
    for(gap = s/2;gap>0;gap/=2)
    {
        for(int j=gap; j<s;j+=1)
        {
            int tmp = a[j];
            int i=0;
            for(i=j;i>=gap && a[i-gap]>tmp;i = i-gap)
            {
                a[i] = a[i-gap];
            }
            a[i] = tmp;
        }
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
    ShellSort(a,s);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
