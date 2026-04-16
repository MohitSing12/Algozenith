#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> res;

void bfs(vector<vector<int>> &adj,int src){
    queue<int> q;
    
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for(auto x:adj[curr]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
   
}

vector<int> bfs_connected(vector<vector<int>> &adj){
    int V=adj.size();
    for(int i=1;i<V;i++){
        if(!visited[i]){
            bfs(adj,i);
        }
    }
    return res;
}

void solve(){
vector<vector<int>> adj;
int n,m;
cin>>n>>m;
adj.resize(n+1);
// res.resize(n+1);
res.clear();
visited.assign(n+1,false);

for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}

vector<int> ans=bfs_connected(adj);
for(auto i:ans){
    cout<<i<<" ";
}
// for(int i=0;i<n;i++){
//     cout<<i<<" : ";
//     for(int j=0;j<adj[i].size();j++){
//         cout<<adj[i][j];
//     }
//     cout<<endl;
// }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
}