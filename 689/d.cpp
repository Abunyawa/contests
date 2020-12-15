// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}
map<ll,int> m;


void mergeCheck(vl a){
    if(a.size()==0) return;
    ll mn = 1e6+1;
    ll mx = -1e6-1;
    ll sm = 0;
    for(int i=0;i<a.size();i++){
        sm+=a[i];
        if(a[i]<mn){
            mn = a[i];
        }
        if(a[i]>mx){
            mx = a[i];
        }
    }
    
    m[sm]++;
    ll mid = (mx+mn)/2;
    vl low;
    vl up;
    for(auto x: a){
        if(x<=mid){
            low.pb(x);
        }else{
            up.pb(x);
        }
    }
    if(low.size()==0 || up.size()==0){
        return;
    }
    mergeCheck(low);
    mergeCheck(up);
}


void solve() {
    int n,q;
    cin>>n>>q;
    m.clear();
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeCheck(a);
    for(int i=0;i<q;i++){
        ll p;
        cin>>p;
        if(m[p]>0){
            yes();
        }else{
            no();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

