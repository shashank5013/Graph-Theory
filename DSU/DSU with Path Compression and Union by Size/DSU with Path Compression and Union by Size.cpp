/*  
    The overall Time complexity of the algorithm after
    using Path Compression and Union by Size is 
    ≈ O(4*m) .
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
vector<int>parent;
unordered_map<int,int>size;
int find(int a)                      
{
    if(a==parent[a]){return a;}
    else
    {
        return parent[a]=find(parent[a]);   //Path Compression
    }
    

}
void Union(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y){return ;}
    if(size[x]>size[y])             
    {
        parent[y]=x;                   //Union by Size
        size[x]+=size[y];
        size.erase(y);
    }
    else
    {
        parent[x]=y;
        size[y]+=size[x];
        size.erase(x);
    }
    
}
void solve()
{
    int n,m;cin>>n>>m;
    parent.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        Union(u,v);
    }
    for(auto it:size)
    {
        cout<<it.first<<" "<<it.second<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
