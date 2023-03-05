#include<bits/stdc++.h>
using namespace std;
struct item{
   string s;
   double price,weight,unitprice;
};
bool comparison(item a1, item a2)
{
    return a1.unitprice>a2.unitprice;
}
double knapsack(int capacity,item ar[],int n)
{
    double profit=0;

   for(int i=0;i<n;i++)
   {
        if(capacity>=ar[i].weight)
    {
        profit+=ar[i].price;
        capacity-=ar[i].weight;

    }
    else
    {
        ///cout<<ar[i].s<<" ";
        profit+=ar[i].unitprice*capacity;
        break;
    }
   }
   cout<<endl;

   return profit;
}


int main()
{
    int n,capacity;
    cin>>n>>capacity;
    item ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i].s>>ar[i].weight>>ar[i].price;
        ar[i].unitprice=ar[i].price/ar[i].weight;
    }
    cout<<endl<<endl;
    sort(ar,ar+n,comparison);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i].s<<" "<<ar[i].weight<<" "<<ar[i].price<<" "<<ar[i].unitprice<<endl;
    }
    cout<<"Max profit: ";
    cout<<knapsack(capacity,ar,n)<<endl;

}
