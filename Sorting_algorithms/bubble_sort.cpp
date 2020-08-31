#include<iostream>
using namespace std;
int  BubbleSort(int a[], int s)
{
    int i,j,tmp;
    bool flag;
    for(i=0;i<s;i++)
    {
        flag = false;
        for(j=0;j<(s-i-1);j++)
        {
            if(a[j]>a[j+1])
            {
                flag = true;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1]= tmp;
            }
        }
        if(flag==false)
        {
            break;
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
    BubbleSort(a,s);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
