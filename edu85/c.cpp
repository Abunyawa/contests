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
bool cmp(ll a, ll b){
    return a>b;
}
void solve(){
    int n;
    cin>>n;
    vl ar(n,0);
    vl p(n);
    vl p2(n);

    ll mn = 9999999999999;
    int ind;
    for(int i = 0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        p[i] = a;
        p2[i] = b;
        ar[i] += a;
        ar[(i+1)%n] -= b;
    }
    ll ans = 9999999999999;
    for(int i = 0;i<n;i++){
        if(min(p[(i+1)%n],p2[i]) < mn){
            mn = min(p[(i+1)%n],p2[i]);
            ind = (i+1)%n;
        }
    }
    ll sm = 0;
    for(int i = 0;i<n;i++){
        sm+=max(ar[i],0ll); 
    }
    for(int i = 0;i<n;i++){
        if(sm-max(ar[i],0ll)+p[i]<ans){
            ans = sm-max(ar[i],0ll)+p[i];
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
