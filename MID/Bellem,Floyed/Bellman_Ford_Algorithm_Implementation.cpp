#include <bits/stdc++.h>
using namespace std;

int n, m;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e9 + 3;
vector<pair<pii, int>> list_of_adges;
vector<pii> adj[N];
vector<int> d(N, INF);

void bellaman_ford(int s)
{
    d[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (auto vpair : adj[j])
            {
                int v = vpair.first;
                int w = vpair.second;
                if ((d[j] != INF) && (d[v] > d[j] + w))
                {
                    d[v] = d[j] + w;
                }
            }
        }
    }
}

// void bellaman_ford(int s)
// {
//     d[s] = 0;
//     for (int i = 1; i < n; i++)
//     {
//         for (auto node : list_of_adges)
//         {
//             int u = node.first.first;
//             int v = node.first.second;
//             int w = node.second;
//             if ((d[u] != INF) && (d[v] > d[u] + w))        // different way    
//             {
//                 d[v] = d[u] + w;
//             }
//         }
//     }
// }

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // list_of_adges.push_back({{u, v}, w});
    }

    bellaman_ford(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "D  " << i << " : " << d[i] << endl;
    }
    return 0;
}

/*
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
4 7 3
*/