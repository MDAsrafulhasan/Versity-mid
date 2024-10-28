#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
vector<int> adj[N];
int level[N];
bool visited[N];
int perent[N];

void bfs(int per)
{
    queue<int> q;
    q.push(per);
    visited[per]=true;
    level[per]=0;
    perent[per]=-1;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int val:adj[f])
        {
            if(visited[val]) continue;
            q.push(val);
            visited[val]=true; 
            level[val]=level[f]+1;
            perent[val]=f;
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

    int s,d;
    cin>>s>>d;
    bfs(s);            // O(n+m)
    cout<<level[d]; 

    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"perent "<<i<<" :"<<perent[i]<<endl;
    }
    vector<int> path;
    while(d!=-1)           // O(n)
    {
        path.push_back(d);
        d=perent[d];
    }
    reverse(path.begin(),path.end());
    for(int node : path)
    cout<<node<<" ";
    return 0;
}

/* 1st one-
7
7
1 2
1 3
3 4
4 6
2 5
5 6
5 7
1
7

2nd one-
7
8
1 2
1 3
3 4
4 6
2 5
5 6
5 7
3 7
1
7
*/
