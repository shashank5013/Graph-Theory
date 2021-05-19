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
bool dfs(vector<int> adj[], vector<bool>&visited, vector<int>&color, int x)
{
  if (visited[x]) {return true;}
  visited[x] = true;
  for (auto node : adj[x])
  {
    if (color[node] == -1)
    {
      if (color[x]) {color[node] = 0;}
      else {color[node] = 1;}
    }
    else if (color[node] == color[x])
    {
      return false;
    }
    if (dfs(adj, visited, color, node) == false)
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
  int t; cin >> t;
  for (int k = 1; k <= t; k++)
  {
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= m; i++)
    {
      int u, v; cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    vector<int>color(n + 1, -1);
    bool bipartite = true;
    for (int i = 1; i <= n and bipartite; i++)
    {
      if (!visited[i])
      {
        color[i] = 0;
        if (dfs(adj, visited, color, i))
        {
          bipartite = true;
        }
        else
        {
          bipartite = false;
        }
      }
    }
    if (bipartite)
    {
      cout << "Graph is bipartite\n";
    }
    else
    {
      cout << "Graph is bipartite\n";
    }

  }
  return 0;
}
