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
int n,m;
vector<vector<bool>>visited;
bool is_valid(int x,int y)
{
    if(x<1 or y<1 or x>n or y>m or ::visited[x][y])
    {
        return false;
    }
    return true;
}
void dfs(int x,int y)  //here  x means row number and y means column number
{
    cout<<x<<" "<<y<<"\n";
    visited[x][y]=true;
    if(is_valid(x+1,y)){dfs(x+1,y);}
    if(is_valid(x-1,y)){dfs(x-1,y);}
    if(is_valid(x,y+1)){dfs(x,y+1);}
    if(is_valid(x,y-1)){dfs(x,y-1);}
}
void solve()
{
    cin>>n>>m;
    visited.assign(n+1,vector<bool>(m+1,false));
    dfs(1,1);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

