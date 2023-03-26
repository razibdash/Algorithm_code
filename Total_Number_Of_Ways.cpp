#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter The Amount Of Coin: ";
    cin>>n;
    int amount;
    cout<<"Enter The Amount: ";
    cin>>amount;
    int ar[n];
    cout<<"Enter The Coin: ";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int table[n+1][amount+1];
    for(int i=0;i<=n;i++)
    {
        table[i][0]=1;
    }
    for(int j=1;j<=amount;j++)
    {
        table[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        int a=ar[i-1];
        for(int j=1;j<=amount;j++)
        {
            if(ar[i-1]<=j)
            {
                table[i][j]=table[i-1][j]+table[i][j-a];
            }
            else
            {
                table[i][j]=table[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Total Number Of ways: "<<table[n][amount];
}
