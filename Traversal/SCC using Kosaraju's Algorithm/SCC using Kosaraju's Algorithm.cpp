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
vector<vector<int>>adj,trp; //trp represents transposed graph
vector<bool>visited;
vector<int>out_time;
void dfs_for_adj(int curr_node)
{
    visited[curr_node]=true;
    for(auto node:adj[curr_node])
    {
        if(!visited[node])
        {
            dfs_for_adj(node);
        }
    }
    out_time.pb(curr_node);
}
void dfs_for_trp(int curr_node)
{
    cout<<curr_node<<" ";
    visited[curr_node]=true;
    for(auto node:trp[curr_node])
    {
        if(!visited[node])
        {
            dfs_for_trp(node);
        }
    }
}

void solve()
{
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    trp.resize(n+1);
    visited.assign(n+1,false);
    for(int i=1;i<=m;i++)
    {
       int u,v;cin>>u>>v;
       adj[u].pb(v);
       trp[v].pb(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])       //for storing nodes according to their out times in out_time vector
        {
            dfs_for_adj(i);
        }
    }
    visited.assign(n+1,false);
    reverse(out_time.begin(),out_time.end());
    int scc=0;
    for(auto node:out_time)
    {
        if(!visited[node])
        {
            dfs_for_trp(node);
            scc++;
            cout<<"\n";
        }
    }
    cout<<scc;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}