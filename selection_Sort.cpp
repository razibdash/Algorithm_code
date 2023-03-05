#include<bits/stdc++.h>
using namespace std;
int sorted(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(array[j]<array[min_index])
                min_index=j;
        }
        int temp=array[i];
        array[i]=array[min_index];
        array[min_index]=temp;
    }
}
int main()
{
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;
    cout<<endl;
    int array[n];
    cout<<"Enter The Numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<endl;
    cout<<"Unsorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    sorted(array,n);

    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
}
