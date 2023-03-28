#include<bits/stdc++.h>
using namespace std;
struct item
{
    string s;
    int price,weight;
};
int main()
{
    int n;
    cout<<"Enter The Item Number: ";
    cin>>n;
    item ar[n];
     cout<<"Enter Item Price Weight: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i].s>>ar[i].price>>ar[i].weight;
    }

    int capacity;
    cout<<"Enter The knapsack Capacity: ";
    cin>>capacity;
    int row=n;
    int col=capacity;

    int table[row+1][col+1];

    for(int i=0;i<=row;i++)
    {
        table[i][0]=0;
    }
    for(int j=0;j<=col;j++)
    {
        table[0][j]=0;
    }



     for(int i=1;i<=row;i++)
     {
         for(int j=1;j<=col;j++)
         {
             int w=ar[i-1].weight;
             int p=ar[i-1].price;
             if(w<=j)
             {
                 table[i][j]=max(table[i-1][j],table[i-1][j-w]+p);
             }
             else
             {
                 table[i][j]=table[i-1][j];
             }

         }
     }




    for(int i=0;i<=row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Max Profit: "<<table[row][col]<<endl;

    cout<<"Selected Item: ";

    int i=n;
    int j=capacity;
    while(i>0&&j>0)
    {
        if(table[i][j]==table[i-1][j])
        {
            i--;
        }
        else
        {
            cout<<ar[i-1].s<<" ";
            i--;
            j-=ar[i].weight;
        }
    }


    /*
    input value
    n=4
    capacity=7
    item p w
    1    1  1
    2    4  3
    3    5  4
    4    7  5

    max profit = 9

    selected item= 3,2
    */


}
