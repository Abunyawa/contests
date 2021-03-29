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
    int n,b;
    cin>>n>>b;
    vi cost;
    int ev=0;
    int od=0;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            ev++;
        }else{
            od++;
        }
        if(od==ev){
            if(i+1<n){
                cost.pb(abs(a[i+1]-a[i]));
            }
            ev = 0;
            od = 0;
        }
    }

    sort(all(cost));
    int ans = 0;
    int cur = 0;
    for(int i=0;i<cost.size();i++){
        cur+=cost[i];
        if(cur<=b){
            ans++;
        }else{
            break;
        }
    }

    cout<<ans<<'\n';
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

