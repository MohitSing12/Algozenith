#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

vector<vector<int>> arr;
vector<int> visited;
bool iscycle=false;
vector<int> cnt_cycle;
vector<int> par;

void dfs(int node,int parent){
    visited[node]=2;
     par[node]=parent;

    for(auto v:arr[node]){

        if(visited[v]==1){
           
            dfs(v,node);
        }
        else if(visited[v]==2){
            //cycle detection
            if(!iscycle){
                int temp=node;
                while(temp!=v){
                    cnt_cycle.pb(temp);
                    temp=par[temp];
                }
                cnt_cycle.pb(temp);
            }
            iscycle=true;
            reverse(cnt_cycle.begin(),cnt_cycle.end());
        }
        else{ 
            //cross cycle detection
        }
    }
    visited[node]=3;
}

void solve(){
    int n,m;
    cin>>n>>m;
    
    arr.resize(n+1);
    cnt_cycle.clear();
    par.assign(n+1,0);

    visited.assign(n+1,1);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        arr[x].pb(y);
    }
    dfs(1,0);
    

    if(iscycle){
        cout<<"True"<<'\n';
    }

    for(auto i:cnt_cycle){
        cout<<i<<" ";
    }

}
signed main() {
    fastio();
    int t=1;
    //cin>>t;
    while(t--){
    solve();
}
    return 0;
}