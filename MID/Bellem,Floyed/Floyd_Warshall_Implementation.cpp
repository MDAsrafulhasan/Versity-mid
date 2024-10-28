#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e3 + 2;
int a[N][N];
const int INF = 1e9 + 5;

void matrix_initialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                a[i][j] = INF;
        }
    }
}

void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == INF)
                cout << "X ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    matrix_initialize();
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        // a[v][u]=w;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }

    print_matrix();
    return 0;
}

/*
5
7
1 2 2
1 3 6
2 3 1
3 4 4
4 2 6
2 5 3
5 4 9
*/