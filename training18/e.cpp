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
int poses[2000];

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int for1e = a;
    int for2e = b;
    int for2s = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        int u;
        cin>>u;
        if(u==1){
            if(for1e>0){
                for1e--;
            }else if(for2e>0){
                for2e--;
                for2s++;
            }else if(for2s>0){
                for2s--;
            }else{
                ans++;
            }
        }else{
            if(for2e>0){
                for2e--;
            }else{
                ans+=2;
            }
        }
    }
    cout<<ans<<'\n';
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
