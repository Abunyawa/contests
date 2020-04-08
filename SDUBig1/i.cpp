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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
vector<int> g[200100];
int ctr = 0;
bool used[200100];
void dfs(int v){
    used[v] = true;
    bool fl = false;
    for(int i = 0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            fl = true;
            dfs(g[v][i]);
        }
    }
    if(!fl){
        ctr++;
    }
}

void solve(){
    int n;
    cin>>n;
    map<int,vector<ll>> m;
    for(int i=0;i<n;i++){
        ll a,c;
        cin>>a>>c;
        m[c].pb(a);
    }
    for(auto x: m){
        vector<ll> cur = x.S;
        for(int i=1;i<cur.size();i++){
            if(cur[i]<cur[i-1]){
                no();
                return;
            }
        }
    }
    yes();
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
