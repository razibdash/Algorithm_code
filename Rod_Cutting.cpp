#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"\t Rod Cutting"<<endl;
    int n;
    cout<<"Enter The Number Of Length: ";
    cin>>n;
    cout<<"Enter Total Length: ";
    int l;
    cin>>l;
    int length[n];
    int profit[n];
    cout<<"Enter Length and Profit:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>length[i]>>profit[i];
    }
    int table[n+1][l+1];
    for(int i=0;i<=n;i++)
    {
        table[i][0]=0;
    }
    for(int j=0;j<=l;j++)
    {
        table[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        int ln=length[i-1];
        int p=profit[i-1];
        for(int j=1;j<=l;j++)
        {
            if(ln<=j)
            {
                table[i][j]=max(table[i-1][j],table[i][j-ln]+p);
            }
            else{
                table[i][j]=table[i-1][j];
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=l;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Max Profit Is: "<<table[n][l]<<endl;;
    cout<<"Selected Item Is: ";
    int i=n;
    int j=l;
    while(j>0&&i>0)
    {
        if(table[i][j]==table[i-1][j])
        {
            i--;
        }
        else{
            cout<<length[i-1]<<" ";

            j-=i;
        }
    }



}
