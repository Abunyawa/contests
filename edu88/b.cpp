#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int d[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            if(a=='.'){
                d[i][j] = 0;
            }else{
                d[i][j] = 1;
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j!=m-1){
                if(d[i][j]==0){
                    if(d[i][j+1]==0){
                        ans += min(y,2*x);
                        j++;
                    }else{
                        ans+=x;
                        j++;
                    }
                }
            }else{
                if(d[i][j]==0){
                    ans+=x;
                }
            }
        }
    }
    cout<<ans<<'\n';
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
