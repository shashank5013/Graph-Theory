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
class edge  // describes an edge between a and b with weight wt
{
    public:
    int a,b,wt;
    edge(int a,int b,int wt)
    {
        this->a=a;
        this->b=b;
        this->wt=wt;
    }
};
ll wt_sum=0;
vector<edge>adj;
vector<int>parent;
unordered_map<int,int>size;
bool cmp(edge temp1,edge temp2)
{
    return temp1.wt<temp2.wt;
}
int find(int a)
{
    if(parent[a]==a){return a;}
    else
    {
        return parent[a]=find(parent[a]);
    }
    
}
void Union(edge temp)
{
    int a=temp.a,b=temp.b;
    a=find(a);
    b=find(b);
    if(a==b){return ;}
    else
    {
        wt_sum+=temp.wt;
        if(size[a]>size[b])
        {
            parent[b]=a;
            size[a]+=size[b];
            size.erase(b);
        }
        else
        {
            parent[b]=a;
            size[b]+=size[a];
            size.erase(a);
        }
        
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
        int a,b,wt;cin>>a>>b>>wt;
        edge temp(a,b,wt);
        adj.pb(temp);
    }
    sort(adj.begin(),adj.end(),cmp);
    for(auto it:adj)
    {
       Union(it);
    }
    cout<<wt_sum;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    

    return 0;
}
