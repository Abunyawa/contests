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

bool isOk(vl a, ll m){
    int n = a.size();
    vi canAdd(n,0);

    for(int i = n-1;i>1;i--){
        ll free;
        if(canAdd[i]>=m){
            free = a[i];
        }else{
            free = a[i] - (m-canAdd[i]);
        }

        if(free<0){
            return false;
        }
        ll d = free/3LL;
        a[i] -= 3*d;
        canAdd[i-1] += d;
        canAdd[i-2] += 2LL*d; 
    }
    
    for(int i=0;i<n;i++){
        if(canAdd[i]+a[i]<m){
            return false;
        }
    }

    return true;
}

void solve() {
    int n;
    cin>>n;
    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll l = 0;
    ll r = 1e9;

    //cout<<isOk(a,7)<<'\n';
    
    while(l<r-1){
        ll m = (l+r)/2;

        if(isOk(a,m)){
            l = m;
        }else{
            r = m;
        }

    }

    cout<<l<<'\n';

    
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

