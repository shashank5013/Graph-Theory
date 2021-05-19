/* This algorithm can be used to 
find bridges in a graph using dfs in 
O(n+m) time complexity
*/
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
vector<vector<int>>adj;
vector<bool>visited;
vector<int>in,low;
int timer;
void dfs(int curr_node,int parent)
{
    visited[curr_node]=true;
    in[curr_node]=low[curr_node]=++timer;
    for(auto node:adj[curr_node])
    {
        if(node==parent){continue;}
        else if(visited[node])
        {
            low[curr_node]=min(low[curr_node],in[node]);
        }
        else
        {
            dfs(node,curr_node);
            low[curr_node]=min(low[curr_node],low[node]);
            if(low[node]>in[curr_node])
            {
                cout<<node<<" "<<curr_node<<"\n";
            }
        }
        
    }

}
void solve()
{
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    visited.assign(n+1,false);
    in.resize(n+1);low.resize(n+1);
    timer=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
