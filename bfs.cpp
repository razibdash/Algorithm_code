 #include<bits/stdc++.h>
using namespace std;
#define MAX 100
vector<char>v[MAX];
bool vis[MAX];
void bfs()
{
    queue<char>q;
    q.push('A');
    vis['A']=true;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        for(auto it:v[q.front()])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=true;
            }
        }
        q.pop();
    }
}
int main()
{
   v['A'].push_back('B');
   v['A'].push_back('C');
   v['A'].push_back('D');

   v['B'].push_back('E');

   v['C'].push_back('B');
   v['C'].push_back('G');

   v['D'].push_back('G');
   v['D'].push_back('C');

   v['E'].push_back('F');
   v['E'].push_back('C');

   v['F'].push_back('H');
   v['F'].push_back('C');

   v['G'].push_back('I');
   v['G'].push_back('F');

   v['H'].push_back('I');
   v['H'].push_back('E');

   v['I'].push_back('F');
   bfs();
}

