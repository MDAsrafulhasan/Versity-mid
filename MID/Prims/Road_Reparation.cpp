#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pii;
typedef pair<int, int> pi;
const int N = 1e5 + 2;
vector<pi> adj[N];
bool visited[N];

void prims_algo(int perent,int n)
{
    int cnt=0;
    vector<pii> edge_list;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, {perent, perent}});
    while (!pq.empty())
    {
        pii f = pq.top();
        // cout<<f.first<<" "<<f.second.first<<" "<<f.second.second<<endl;
        int w = f.first;
        int u = f.second.first;
        int v = f.second.second;
        pq.pop();
        if (visited[v])
            continue;
        visited[v] = true;
        cnt++;
        edge_list.push_back({u, {v, w}});
        for (pi child : adj[v])
        {
            int node = child.first;
            int ww = child.second;
            if (!visited[node])
            {
                pq.push({ww , {v, node}});
            }
        }
    }
    long long int sum=0;
    for (pii child : edge_list)
    {
        sum+= child.second.second;
    }
    (n==cnt)? cout<<sum : cout<<"IMPOSSIBLE";
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims_algo(1,n);
    return 0;
}