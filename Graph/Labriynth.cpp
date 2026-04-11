#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

using state=pair<int,int>;
vector<vector<int>> dist,vis;
vector<string> adj;
vector<vector<state>> parent;
int n,m;

bool is_valid(int x,int y){
    if(x>=0&&x<n && y>=0&&y<m && adj[x][y]!='#'){
        return 1;
    }
    return 0;
}
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};

vector<state> neighbours(state cur){
    vector<state> neigh;
    for(int dir=0;dir<4;dir++){
        int nx=cur.F+dx[dir];
        int ny=cur.S+dy[dir];
        if(is_valid(nx,ny)){
            neigh.push_back({nx,ny});
        }
    }
    return neigh;
}

void bfs(state st){

    queue<state> q;
    vis=vector<vector<int>>(n,
               vector<int>(m,0));
    dist=vector<vector<int>>(n,
                vector<int>(m,1e7));
    
    parent=vector<vector<state>>(n,vector<state>(m,{-1,-1}));

    dist[st.F][st.S]=0;
    q.push(st);

    while(!q.empty()){
        state curr=q.front();
        q.pop();
        if(vis[curr.F][curr.S])continue;
        vis[curr.F][curr.S]=1;

        for(auto neigh:neighbours(curr)){
            if(!vis[neigh.F][neigh.S] && dist[neigh.F][neigh.S]>dist[curr.F][curr.S]+1){
                parent[neigh.F][neigh.S]=curr;
                dist[neigh.F][neigh.S]=dist[curr.F][curr.S]+1;
                q.push(neigh);
            }
        }
    }            

}
void solve(){

cin>>n>>m;
adj.resize(n);
for(int i=0;i<n;i++){
    cin>>adj[i];
}

state st,en;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(adj[i][j]=='A'){
            st.F=i;
            st.S=j;
        }
        else if(adj[i][j]=='B'){
            en.F=i;
            en.S=j;
        }
    }
}
bfs(st);
if(dist[en.F][en.S]!=1e7){
    cout<<"YES"<<'\n';
    cout<<dist[en.F][en.S]<<'\n';

vector<state> path;
state cur=en;
while(cur!=st){
    path.push_back(cur);
    cur=parent[cur.F][cur.S];
}
path.push_back(st);
reverse(path.begin(),path.end());
for(int i = 1; i < path.size(); i++) {
        int prev_r = path[i-1].first;
        int prev_c = path[i-1].second;
        int curr_r = path[i].first;
        int curr_c = path[i].second;

        if(curr_c < prev_c) {
            cout << "L";
        }
        else if(curr_r > prev_r) {
            cout << "D";
        }
        else if(curr_c > prev_c) {
            cout << "R";
        }
        else {
            cout << "U";
        }
    }
}
else{
    cout<<"NO"<<'\n';
}
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

}