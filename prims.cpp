#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter The Number of vertex: ";
    cin >> n;
    int edge;
    cout << "Enter The Number of Edges: ";
    cin>> edge;
    int st,l=1;
    cout << "Enter The Starting Node: " ;
    cin >> st;
    if(st>0)
    {
        n+=1;
        l = 2;
    }
    vector<pair<int, int > > adj[n];

    /*Take Input for Graph */
    for(int i =0; i<edge; i++)
    {
        int u,v,wt;
        cin >> u  >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >  > pq;

    int key[n]; // weight stored for the visited node
    int parent[n]; // when the weight changed then the parent will be added there
    bool inMST[n]; // node visited or not

    for(int i=0; i<n; i++)
    {
        key[i]=INT_MAX; // Every key value made infinity.
        inMST[i]= false;// Visiting node all false.
    }
    key[st] = 0;
    parent[st]=-1;
    pq.push({0,st}); // this pair:  first value weight for this node, second value node

    while(!pq.empty())
    {
        int p_node = pq.top().second;//staring node
        pq.pop();
        inMST[p_node] = true;

        for(auto it:adj[p_node])
        {
            int v = it.first; // under staring node all nodes
            int weight = it.second; // current node weight
            if(inMST[v]==false && weight<key[v])
            {
                key[v] = weight; // under staring node all node
                parent[v] = p_node; // changed weight parent valuse added.
                pq.push({key[v], v});
            }
        }
    }
    int cost =0;
    cout << "Primes MST: " << endl;
    for(int i =l; i<n; i++)
    {
        cost+=key[i];
        cout << parent[i] << " - " << i << endl;
    }
    cout << "Total Cost: " << cost << endl;

    return 0;
}


