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
vector<int>arr[100005];
void dfs(bool visi[],int i){
   // cout<<i<<" ";
    visi[i]=true;
    for(int j=0;j<sz(arr[i]);j++){
        if(!visi[arr[i][j]]) dfs(visi,arr[i][j]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
   // cin>>t;
    while(t--){
        //Adjacency List
        //Best Practise Declare Global 2D Array and Visited Array because You
        int node,edges;
        cin>>node>>edges;
        while(edges--){
            int a,b;
            cin>>a>>b;
            arr[a].eb(b);
            arr[b].eb(a);
        }
        //DFS(Depth First Search)
        bool visi[node+1]={false};
        int ans{0};
        for(int i=1;i<=node;i++){
            if(!visi[i]){
                dfs(visi,i);
                //Count Number of Connected Components
                ans++;//This will Give Number of components
            }
        }
        cout<<ans<<endl;
    }
 return 0;
}