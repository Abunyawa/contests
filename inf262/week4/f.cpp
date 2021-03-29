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
    ll pro = 1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=0){
            a[i] = -a[i]-1LL;
        }
        pro *= a[i];
    }
    if(n%2==1){
        int mn = 1;
        int ind = -1;
        for(int i=0;i<n;i++){
            if(a[i]<mn){
                mn = a[i];
                ind = i;
            }
        }

        a[ind] = -a[ind]-1;
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
    
    while (tt--) {
        solve();
    }

    return 0;
}

