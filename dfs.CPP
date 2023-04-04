#include<bits/stdc++.h>
using namespace std;
#define MAX 100
vector<int>v[MAX];
bool vis[MAX];
void dfs( int s)
{
    cout<<s<<" ";
    vis[s]=true;
    for(auto it:v[s])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }


}
int main()
{
   v[0].push_back(3);
   v[0].push_back(1);

   v[1].push_back(0);
   v[1].push_back(3);
   v[1].push_back(2);
   v[1].push_back(6);
   v[1].push_back(5);

   v[2].push_back(3);
   v[2].push_back(1);
   v[2].push_back(5);

   v[3].push_back(0);
   v[3].push_back(1);
   v[3].push_back(2);
   v[3].push_back(4);

   v[4].push_back(3);
   v[4].push_back(2);
   v[4].push_back(6);

   v[5].push_back(4);
   v[5].push_back(1);

   v[5].push_back(1);
   v[5].push_back(2);


   dfs(0);
}
