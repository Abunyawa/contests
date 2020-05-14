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

vector<ll> g[100100];
bool used[100100];
int mx = 0;

void dfs(int v,int dist){
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        dfs(g[v][i] , dist+1);        
    }
    if(dist>mx){
        mx = dist;
    }
}

void solve(){
    int n;
    ll k;
    cin>>n>>k;
    vl a(n);
    bool flag = false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k) a[i] = 1;
        else if(a[i]>k) a[i] = 2;
        else a[i] = 0;

        if(a[i]==1) flag =true;
    }
    if(!flag){
        no();
        return;
    }
    if(n==1){
        yes();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n && j-i<=2;j++){
            if(a[i]>0 && a[j]>0){
                yes();
                return;
            }
        }
    }
    no();
    return;

}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
