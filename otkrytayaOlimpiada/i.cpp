// chrono::system_clock::now().time_since_epoch().count()
//#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#include<vector>
#include<stdio.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;


vi g[100001];
bool used[100001];
vi f[1000001];

vector<int> valid1[1000001];
vector<int> valid2[1000001];
ll ctr[1000001];
ll ans[1000001];
ll sz;

void dfs(int v){
    sz++;
    used[v] = true;

    for(auto to: g[v]){
        if(!used[to]){
            dfs(to);
        }
    }

    g[v].clear();
    used[v] = false;
}

void solve() {
    int n;
    scanf("%d", &n);
    
    int edges[n-1][3];
    for(int i=0;i<n-1;i++){
        scanf("%d%d%d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    for(int i=1; i <= 1000000;i++){
        for(int j = i;j<=1000000;j+=i){
            f[j].pb(i);
        }
    }

    for(int i=0;i<n-1;i++){
        for(auto x: f[edges[i][2]]){
            valid1[x].pb(edges[i][0]);
            valid2[x].pb(edges[i][1]);
        }
    }


    for(int i=1;i<=1000000;i++){
        for(int j = 0; j< valid1[i].size();j++){
            int u = valid1[i][j];
            int v = valid2[i][j];
            g[valid1[i][j]].pb(valid2[i][j]);
            g[valid2[i][j]].pb(valid1[i][j]);
        }


        for(int j = 0; j< valid1[i].size();j++){
            if(!used[valid1[i][j]]){
                sz = 0;
                dfs(valid1[i][j]);
                ctr[i] += sz*(sz-1);
            }
        }
        
    }

    ll tot = 0;
    for(int i=1000000;i>0;i--){
        ans[i] = ctr[i];
        for(int j = 2*i;j<=1000000;j+=i){
            ans[i] -= ans[j];
        }
        tot += (ans[i] * i);
    }

    printf("%lld\n",tot);
}

int main() {
    /*
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    */

    solve();
    

    return 0;
}

