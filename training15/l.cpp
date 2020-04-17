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

int binp(vl &a,int n,ll x){
    int l = n,r = a.size()-1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(a[mid]>=x){
            r = mid;
        }else{
            l = mid;
        }
    }

    if(a[r]<=x)
        return r;
    if(a[l]<=x)
        return l;
    return l;
}

void solve(){
    ll n,m,t;
    cin>>n>>m>>t;
    
    unsigned ll ans = 0;
    for(ll i=4;i<t;i++){
        if(t-i<=m && i<=n){

            unsigned ll b = 1;
            for(ll j = n;j>n-i;j--){
                b*=j;
            }
            for(ll j = 2;j<=i;j++){
                b/=j;
            }
            unsigned ll g = 1;
            for(ll j = m;j>m-t+i;j--){
                g*=j;
            }
            for(ll j = 2;j<=t-i;j++){
                g/=j;
            }
            ans+=b*g;
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
