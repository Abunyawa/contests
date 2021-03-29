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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}


struct otr{
    ll len;
    ll l,r;
    int ind;
}



bool cmp(otr a, otr b){
    if(a.len!=b.len){
        return a.len>b.len;
    }else{
        if(a.r!=b.r){
            return a.r<b.r;
        }else{
            return a.l<b.l;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<otr> a(n);
    vector<bool> used(n, true);
    for(int i=0;i<n;i++){
        ll ai;
        ll x;
        cin>>ai>>x;
        otr nw;
        nw.len = x;
        nw.l = ai;
        nw.r = ai+x-1;
        nw.ind = i;
        a[i] = nw;
    }
    sort(all(a),cmp);


    vector<otr> ans;
    ll t=0;

    for(int i=0;i<n;i++){
        
    }


    cout<<t<<'\n';
    for(auto x: ans){
        cout<<x<<' ';
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

