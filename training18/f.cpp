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

int g[10][10];

void solve(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<5;k++){
                if(j!=k && i!=j && i!=k && g[i][j]==g[i][k] && g[i][k]==g[j][k]){
                    cout<<"WIN\n";
                    return;
                }
            }
        }
    }

    cout<<"FAIL\n";
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
