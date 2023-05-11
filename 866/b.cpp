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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    string s;
    cin>>s;
    int n = s.length();
    vl bl;
    int cur = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cur++;
        }else{
            if(cur!=0) bl.pb(cur);
            cur = 0;
        }
    }

    if(cur!=0){
        if(bl.size()>0){
            if(s[0]=='1') bl[0]+=cur;
            else bl.pb(cur);
        }else{
            if(cur!=0) bl.pb(cur);
        }
    }

    sort(all(bl));


    if(bl.size()<=0){
        cout<<0<<'\n';
        return;
    }else{
        ll ans = bl[bl.size()-1];
        ll pd =bl[bl.size()-1];

        if(pd==n){
            cout<<pd*pd<<'\n';
            return;
        }
        for(ll i=1;i<=pd;i++){
            ans = max(i*(pd-i+1), ans);
        }
        cout<<ans<<'\n';
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

