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
    ll n,k;
    cin>>n>>k;
    if(n<=k){
        cout<<1<<'\n';
        return;
    }
    ll tmpn = n;
    vl fa;
    int ans = n;
    for(ll i = 1;i<=min((ll)sqrt(n),k);i++){
        if(n%i==0){
            if(i<=k && n/i<=k){
                if(ans>min(i,n/i)){
                    ans = min(i,n/i);
                }
            }else{
                if(i<=k){
                    if(ans>n/i){
                        ans = n/i;
                    }
                }else if(n/i<=k){
                    if(ans>i){
                        ans  = i;
                    }
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
