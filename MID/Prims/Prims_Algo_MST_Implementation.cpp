#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pii;
typedef pair<int, int> pi;
const int N = 1e5 + 2;
vector<pi> adj[N];
bool visited[N];

void prims_algo(int perent)
{
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
    for (pii child : edge_list)
    {
        cout << child.first << " " << child.second.first << " " << child.second.second << endl;
    }
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

    prims_algo(1);
    return 0;
}

/*
8 11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
3 4 11
4 8 9
4 7 11
7 6 1
8 6 2
*/