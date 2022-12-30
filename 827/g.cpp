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
    int n = 0;
    cin>>n;

    vector<ll> b(n);
    vector<pair<ll,int>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        b[i] = a[i].fi;
        a[i].se = i;
    }

    vector<bool> used(n, false);

    vector<ll> ans;
    for(int i=35;i>=0;i--){
        ll cur = (1<<i);

        

        sort(rall(a));

        for(int j=0;j<n;j++){
            if(a[j].fi>=cur){
                a[j].fi-=cur;
            }
        }

    
        if(!used[a[0].se]){
            ans.pb(b[a[0].se]);
            used[a[0].se] = true;
        }
    }

    for(int i=0;i<n;i++){
        if(!used[a[i].se]){
            ans.pb(b[a[i].se]);
        }
    }

    for(int i=0;i<n;i++){ 
        cout<<ans[i]<<' ';
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

