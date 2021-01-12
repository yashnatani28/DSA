//Change in dev Branch
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define MA 10e+18
int va=10e8+7;
ll val[200007]={0};
using namespace std;
//Conditional Operator (condition?true part:false part) eg : cout<<(y<=3?"YES":"NO")<<endl;
//string s(3,'1');
// if number of elements in array >10^5 then declare global array.
ll getmul(ll n){ll int k{0};while(n>0){k+=n%10;n=n/10;}return k;}//Sum OF n DIGITS 
vector<int>arr[20005];
bool vis[20005]={false};
vector<int>in(20005);
vector<int>out(20005);
int ti=1;
void dfs(int i){
    in[i]=ti++;
    vis[i]=true;
    for(auto child:arr[i]){
        if(!vis[child]) dfs(child);
    }
    out[i]=ti++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
    cin>>t;
    while(t--){
       int u,v;
       cin>>u>>v;
       while(v--){
           int a,b;
           cin>>a>>b;
           arr[a].eb(b);
           arr[b].eb(a);
       }
       int ans{0};
       for(int i=1;i<=u;i++){
           if(!vis[i]) dfs(i),ans++;
       }
   //    cout<<ans<<endl;
       for(int i=1;i<=u;i++) cout<<in[i]<<" ";
       cout<<endl;
       for(int i=1;i<=u;i++) cout<<out[i]<<" ";
       cout<<endl;
    }
 return 0;
}