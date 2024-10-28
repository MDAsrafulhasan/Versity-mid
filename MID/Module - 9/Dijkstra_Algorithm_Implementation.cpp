#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int inf = 1e9 + 10;
vector<pair<int, int>> adj[N];
int level[N];
bool visited[N];
vector<int> dist(N, inf);

void dikstra(int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({dist[source], source}); // first - distance , second - node.
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (pair<int, int> v_pair : adj[u])
        {
            int v = v_pair.first;
            int w = v_pair.second;
            if (visited[v])
                continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
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

    //dikstra(1);

    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int s, d;
        cin >> s >> d;
        dikstra(s);
        cout << dist[d] << endl;
        for (int i = 1; i <= n; i++)
        {
            dist[i] = INT_MAX;
            visited[i]=false;
        }
    }

   // for (int i = 1; i <= n; i++)
    //{
    //    cout << "distance of node " << i << " : " << dist[i] << endl;
   // }

    return 0;
}
