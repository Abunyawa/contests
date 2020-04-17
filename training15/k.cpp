#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}
vector<int> g[200100];
int leaf[200100];
bool used[200100]; 
bool ans = true;
void dfs(int v,int p){
    used[v] = true;
    bool flag = true;
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            dfs(g[v][i],v);
            flag = false;
        }
    }
    if(flag){
        leaf[p]++;
    }else{
        if(leaf[v]<3){
            ans = false;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        g[x].pb(i+1);
    }
    dfs(1,-1);
    if(ans){
        yes();
    }else{
        no();
    }

}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
