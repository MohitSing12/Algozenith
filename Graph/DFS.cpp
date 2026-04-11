#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
vector<int> visited;
vector<int> comp;

void printer(){
    for(auto i:comp){
        
        cout<<i<<" ";
    }
}

void DFS(int node,int com){
    // visited[node]=1;
        comp[node]=com;
    for(auto i:arr[node]){
        
        if(!visited[i]){
            visited[i]=com;
            

            DFS(i,com);
        }
    }
}

void solve(){
int n,m;
cin>>n>>m;
arr.resize(n+1);
visited.assign(n+1,0);
comp.resize(n+1,0);

for(int i=1;i<=m;i++){
    int x,y; 
    cin>>x>>y;
    arr[x].push_back(y);
    arr[y].push_back(x);

}
int num=0;
for(int i=1;i<=n;i++){

if(!visited[i]){
num++;
DFS(i,num);
}
// visited.assign(n+1,0);  
}

vector<int> comp_size(num+1,0);
for(int i=1;i<=n;i++){
    comp_size[comp[i]]++;

}
for(int i=1;i<=n;i++){
    cout<<i<<" : "<<comp_size[i]<<endl;
    
}

printer();

// DFS(5);
// printer();

// for(int i=1;i<n;i++){
//     cout<<i<<" : ";
//     for(int j=1;j<arr[i].size();j++){
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
// }


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