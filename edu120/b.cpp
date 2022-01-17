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
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    string s;
    cin>>s;
    ll ctr = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            ctr++;
        }
    }
    vector<pair<ll,int>> badU;
    vector<pair<ll,int>> badD;
    for(int i=0;i<n;i++){
        if(s[i]=='0' && a[i]>ctr){
            badD.pb({a[i],i});
        }

        if(s[i]=='1' && a[i]<=ctr){
            badU.pb({a[i],i});
        }
    }

    sort(all(badD));
    sort(all(badU));


    for(int i=0;i<badU.size();i++){
        a[badD[i].se] = badU[i].fi;
        a[badU[i].se] = badD[i].fi;
    }

    for(int i=0;i<n;i++){   
        cout<<a[i]<<' ';
    }

    cout<<'\n';
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

