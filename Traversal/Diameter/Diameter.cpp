/*Code to find diameter of a tree
Based on proof given in onenote
2 DFS Required
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
void dfs(int curr_node,vector<int>adj[],vector<bool>&visited,vector<int>&distance)
{
    visited[curr_node]=true;
    for(auto node:adj[curr_node])
    {
      if(!visited[node])
      {
          distance[node]=distance[curr_node]+1;
          dfs(node,adj,visited,distance);
      }
    }
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
  vector<int>distance(n+1,0);
  dfs(1,adj,visited,distance);
  int max_value=0,end_point=1;
  for(int i=2;i<=n;i++)
  {
      if(distance[i]>max_value)
      {
          max_value=distance[i];
          end_point=i;
      }
  }
  fill(visited.begin(),visited.end(),false);
  distance[end_point]=0;
  dfs(end_point,adj,visited,distance);
  cout<<*max_element(distance.begin(),distance.end());


  return 0;
}
