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
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool is_valid(int x,int y)
{
    if(x<1 or y<1 or x>n or y>m or visited[x][y])
    {
        return false;
    }
    return true;
}
void bfs(int startX,int startY)
{
    queue<pair<int,int>>q;
    visited[startX][startY]=true;
    q.push({startX,startY});
    while(!q.empty())
    {
        int x=q.front().ff,y=q.front().ss;q.pop();
        cout<<x<<" "<<y<<"\n";
        for(int i=0;i<4;i++)
        {
            if(is_valid(x+dx[i],y+dy[i]))
            {
                visited[x+dx[i]][y+dy[i]]=true;
                q.push({x+dx[i],y+dy[i]});
            }
        }
        
    }
}
void solve()
{
    cin>>n>>m;
    visited.assign(n+1,vector<bool>(m+1,false));
    bfs(1,1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
