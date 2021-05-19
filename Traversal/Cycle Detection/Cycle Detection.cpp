//This code is for detecting loops (including self loop ) in graph which doesn't contain multiple edges

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
bool dfs(vector<int> adj[], vector<bool>&visited,  int curr_node, int last_node)
{
  if (visited[curr_node]) {return false;}
  visited[curr_node] = true;
  for (auto node : adj[curr_node])
  {
    if (node != last_node and dfs(adj, visited, node, curr_node) == false)
    {
      return false;
    }
  }
  return true;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m; cin >> n >> m;
  vector<int> adj[n + 1];
  vector<bool> visited(n + 1, false);
  for (int i = 1; i <= m; i++)
  {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 1; i <= n ; i++)
  {
    if (!visited[i])
    {
      if (!dfs(adj, visited, i, 0))
      {
        cout << "Graph contains loop";
        return 0;
      }
    }
  }
  cout << "Graph doesn't contains loop";

  return 0;
}
