#include<bits/stdc++.h>
using namespace std;
#define mx 100
vector<int>adj[mx];
bool visit[mx];
void DFS(int start)
{
    stack<int>stk;
    stk.push(start);
    visit[start]=true;
    while(!stk.empty())
    {
        int fnt=stk.top();
         stk.pop();
        cout<<fnt<<" ";
        for(int i=0;i<adj[fnt].size();i++)
        {
            if(!visit[adj[fnt][i]])
            {
                stk.push(adj[fnt][i]);
                visit[adj[fnt][i]]=true;
            }
        }

    }
}
int main()
{
    int e,n;
    cin>>e>>n;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    DFS(0);

}
