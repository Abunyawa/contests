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
bool cmp(ll a,ll b){
    return b<a;
}
void solve(){
    int n;
    cin>>n;
    vl a(n+1);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end(),cmp);
    
    vl ps(n+1);
    ps[0] = 0;
    for(ll i=1;i<=n;i++){
        ps[i] = ps[i-1]+a[i];
        if(ps[i]-(1+i)*i/2ll>ans){
            ans = ps[i]-i*(i+1)/2;
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
