#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
vector<int> adj[N];
int level[N];
bool visited[N];

void bfs(int per)
{
    queue<int> q;
    q.push(per);
    visited[per]=true;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<"Node : "<<f<<endl;
        for(int val:adj[f])
        {
            if(visited[val]) continue;
            q.push(val);
            visited[val]=true;
            level[val]=level[f]+1;
        }
    }

}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);     // bfs level order e print kora hoy.

    cout<<endl;
    for(int i=1;i<m;i++)
    {
        cout<<"Level "<<i<<" :"<<level[i]<<endl;
    }
    return 0;
}

/*
12
11
1 2
1 3
1 10
2 4
2 5
3 9
10 11
10 12
5 6
5 7
6 8
*/


/*
7
8
1 2
1 3
2 7
2 5
2 4
7 6
*/
