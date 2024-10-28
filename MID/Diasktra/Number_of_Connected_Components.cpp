#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
vector<int> adj[N];
bool visited[N];

void dfs(int per)
{
    visited[per] = true;
    cout << per << " ";
    for (int child : adj[per])
    {
        if (visited[child]) continue;
        dfs(child);
    }
}

void bfs(int per)
{
    queue<int> q;
    q.push(per);
    visited[per] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int val : adj[f])
        {
            if (visited[val])
                continue;
            q.push(val);
            visited[val] = true;
        }
    }
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

    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cout<<endl;
        cc++;
    }

    cout << cc;

    return 0;
}
