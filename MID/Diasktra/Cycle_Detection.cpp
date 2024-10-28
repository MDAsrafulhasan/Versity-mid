#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int c, int p)
{
    bool cycle = false;
    visited[c] = true;
    for (int v : adj[c])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        cycle = dfs(v, c);
    }
    return cycle;
}

int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // if(dfs(1,-1))
    // cout<<"Cycle detected"<<endl;   // 5,4,(1,2),(2,3),(3,5),(5,4),(4,2)
    // else
    // cout<<"No cycle detected"<<endl;

    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])         //8,7,(1,2),(2,3),(3,5),(2,4),(6,7),(6,8),(7,8) 
            continue;
        cycle = dfs(i, -1);
    }

    if (cycle)
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;
    return 0;
}
