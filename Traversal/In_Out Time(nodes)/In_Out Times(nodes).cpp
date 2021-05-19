/*Useful Concept to find if a node lie in subtree of another node
  (or two nodes have the same path)
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
        tree_order_statistics_node_update>
        PBDS;
int timer=0;
void dfs(int curr_node,vector<int>adj[],vector<bool> &visited,vector<int>&in_time,vector<int>& out_time)
{
  if(visited[curr_node]){return ;}
  in_time[curr_node]=++timer;
  visited[curr_node]=true;
  for(auto edge:adj[curr_node])
  {
      dfs(edge,adj,visited,in_time,out_time);
  }
  out_time[curr_node]=++timer;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;cin>>n>>m;
  vector<int>adj[n+1];
  for(int i=1;i<=m;i++)
  {
      int u,v;cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
  }
  vector<bool>visited(n+1,false);
  vector<int>in_time(n+1),out_time(n+1);
  dfs(1,adj,visited,in_time,out_time);
  for(int i=1;i<=n;i++)
  {
      cout<<i<<" "<<in_time[i]<<" "<<out_time[i]<<"\n";
  }

  return 0;
}
