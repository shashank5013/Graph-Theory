#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>PBDS;
struct cmp
{
    bool operator()(pair<int,int>p1,pair<int,int>p2)
    {
       return p1.ss>p2.ss;
    }
};
vector<vector<pair<int,int>>>adj; // first edge then weight (in pair)
vector<bool>visited;
void solve()
{
    int n,m;cin>>n>>m;
    adj.resize(n+1);visited.assign(n+1,false);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({1,0});
    int weight_sum=0;
    while(!pq.empty())
    {
       int curr_node=pq.top().ff,wt=pq.top().ss;pq.pop();
       if(visited[curr_node]){continue;}
       visited[curr_node]=true;
       weight_sum+=wt;
       for(auto node:adj[curr_node])
       {
            pq.push({node.ff,node.ss});                 //difference in bfs and prim's/dijkstra's algorithm 
       }
    }
    cout<<weight_sum;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
