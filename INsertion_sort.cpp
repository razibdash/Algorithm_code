#include<bits/stdc++.h>
using namespace std;
int sorted(int array[],int n)
{
     for(int i=1;i<n;i++)
        {
            int temp=array[i];
            int j=i-1;
            while(array[j]>temp&&j>=0)
            {
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=temp;
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
