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
    int n,x;
    cin>>n>>x;

    if(n%x!=0){
        cout<<-1<<'\n';
        return;
    }

    vi ans(n+1);

    for(int i=1;i<=n;i++){
        ans[i] = i;
    }
    ans[n] = 1;

    ans[1] = x;

    for(int i = x+1;i<=n;i++){
        if(i%x==0 && n%i==0){
            ans[x] = i;
            x = i;
        }
    }

    for(int i=1;i<=n;i++){
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

