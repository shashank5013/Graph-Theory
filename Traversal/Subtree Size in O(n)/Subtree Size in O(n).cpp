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
        tree_order_statistics_node_update>
        PBDS;
int dfs(int curr_node,vector<int>adj[],vector<bool>&visited,vector<int>&subtree)
{
    if(visited[curr_node]){return 0;}
    visited[curr_node]=true;
    subtree[curr_node]=1;
    for(auto node:adj[curr_node])
    {
        subtree[curr_node]+=dfs(node,adj,visited,subtree);
    }
    return subtree[curr_node];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;cin>>n;
  vector<int>adj[n+1];
  for(int i=1;i<n;i++)
  {
      int u,v;cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
  }
  vector<bool>visited(n+1,false);
  vector<int>subtree(n+1);
  dfs(1,adj,visited,subtree);
  for(int i=1;i<=n;i++)
  {
      cout<<i<<" "<<subtree[i]<<"\n";
  }

  return 0;
}
