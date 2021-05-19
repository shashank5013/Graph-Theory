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
vector<int>in,ans;
void topo_sort(int n)
{
    queue<int>q;
    int children=0;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int curr_node=q.front();q.pop();
        for(auto node:adj[curr_node])
        {
            in[node]--;
            if(in[node]==0)
            {
                q.push(node);
            }
            ans.pb(node);
        }
        children++;
    }
    if(children<n)
    {
        cout<<"Not Possible";
    }
    else
    {
        for(auto it:ans)
        {
            cout<<it;
        }
    }
    
}
void solve()
{
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    in.resize(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        in[v]++;
    }
    topo_sort(n);


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
