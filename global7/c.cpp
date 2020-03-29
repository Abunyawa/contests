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
const ll MOD = 998244353;
void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi ind;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(a[i]>=n-k+1){
            ind.pb(i);
            ans+=a[i];
        }
    }
    ll ans1 = 1;
    for(int i=1;i<ind.size();i++){
        ans1 *= (ind[i]-ind[i-1]);
        ans1%=MOD;
    }
    cout<<ans<<' '<<ans1<<endl;
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