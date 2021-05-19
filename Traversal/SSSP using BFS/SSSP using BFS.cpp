/* This works only for unweighted graphs.
for weighted graphs use Dijkstra's algorithm
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
void bfs(int start,vector<int>adj[],vector<bool>&visited,vector<int>&distance)
{
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int curr_node=q.front();q.pop();
        for(auto node:adj[curr_node])
        {
            if(!visited[node])
            {
                distance[node]=distance[curr_node]+1;
                visited[node]=true;
                q.push(node);
                
            }
        }
    }
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
  vector<int>distance(n+1);
  distance[1]=0;
  bfs(1,adj,visited,distance);
  for(int i=1;i<=n;i++)
  {
      cout<<i<<" "<<distance[i]<<"\n";
  }

  return 0;
}
