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

void solve(){
    int n;
    cin>>n;
    int d[n][n];
    for(int i=0;i<n;i++){
        d[0][i] = 1;
        d[i][0] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            d[i][j] = d[i-1][j]+d[i][j-1];
        }
    }
    cout<<d[n-1][n-1]<<'\n';
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
