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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
vector<int> g[100100];
bool used[100100];
int mx = 0;
int ctr = 0;
int ind;
void dfs(int v, int h){
    used[v] = true;
    ctr++;
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            dfs(g[v][i],h);
        }
    }
    if(ctr>mx){
        mx = ctr;
        ind = h;
    }
}

void solve(){
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x!=0)
            g[x].pb(i+1);
        a[i+1] = x;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            ctr = 0;
            dfs(i,i);
        }
    }
    cout<<ind<<' '<<mx<<'\n';

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
