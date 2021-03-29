// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    int n,m;
    cin>>n>>m;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vl b(m+1);
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(rall(a));
    int ptr = 1;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        if(a[i]>ptr){
            ans+=b[ptr++];
        }else if(a[i]==ptr){
            ans+=b[ptr];
        }else{
            ans+=b[a[i]];
        }
    }
    cout<<ans<<'\n';
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

