#include<bits/stdc++.h>
using namespace std;
struct item
{
    char s;
    int st,en;

};
int sorted(item ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[i].en>ar[j].en)
            {
                int t=ar[i].en;
                ar[i].en=ar[j].en;
                ar[j].en=t;

                t=ar[i].s;
                ar[i].s=ar[j].s;
                ar[j].s=t;

                t=ar[i].st;
                ar[i].st=ar[j].st;
                ar[j].st=t;
            }
        }

    }
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<ar[i].s<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<ar[i].st<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<ar[i].en<<" ";
    }
    cout<<endl;
}
void activity(item ar[],int n)
{
    cout<<ar[0].s<<" ";
    cout<<ar[0].en<<" ";
    int i,j=0,c=1;
    for(i=1;i<n;i++)
    {
        if(ar[i].st>=ar[j].en)
        {
            c++;
            cout<<ar[i].s<<" ";
            j=i;
        }
    }
    cout<<endl;
     for(i=1;i<n;i++)
    {
        if(ar[i].st>=ar[j].en)
        {
            c++;
            cout<<ar[i].en<<" ";
            j=i;
        }
    }
    cout<<endl;
    cout<<c;
}
int main()
{
    int n;cin>>n;
    item ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i].s>>ar[i].st>>ar[i].en;
    }
    sorted(ar,n);
    activity(ar,n);

}

