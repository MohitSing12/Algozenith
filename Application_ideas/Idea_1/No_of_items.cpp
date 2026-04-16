#include<bits/stdc++.h>
using namespace std;

void solve(){
int n,m;
cin>>n>>m;
vector<int> arr(n+1);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<int> prefix_arr;
prefix_arr.resize(n,0);
prefix_arr.clear();
if(n > 0){
    prefix_arr.push_back(arr[0]);
}

for(int i=1;i<n;i++){
    
        prefix_arr.push_back(prefix_arr[i-1]+arr[i]);
}
for(auto i:prefix_arr){
    cout<<i<<" ";
}
cout<<endl;
while(m--){
    int x;
    cin>>x;
    auto it=lower_bound(prefix_arr.begin(),prefix_arr.end(),x);
    
    int ans=it-prefix_arr.begin();
    cout<<ans<<'\n';

}

// 
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