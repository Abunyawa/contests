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


const ll INF = 99999999999999999;
void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}


ll w[2010][2010];
ll t[2010][2010];
int n, m;

ll sum (int x, int y,ll U)
{
	ll result = -INF;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		for (int j = y; j >= 0; j = (j & (j+1)) - 1){
            ll cur = t[i][j];
            if(t[i][j]>U){
                cur = -INF;
            }
			result = max(result,cur);
        }
	return result;
}

void inc (int x, int y, ll delta)
{
	for (int i = x; i <= n; i = (i | (i+1)))
		for (int j = y; j <= n; j = (j | (j+1)))
			t[i][j] = max(t[i][j],delta);
}

void solve() {
    cin>>n>>m;
    vl a(n+1);
    vl pref(n+1,0);
    for(int i=0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            t[i][j] = -INF;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j = i;j<=n;j++){
            w[n-i+1][j] = pref[j] - pref[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<w[n-i+1][n-j+1]<<' ';
            inc(i,j,w[n-i+1][n-j+1]);
        }
        cout<<'\n';
    }

    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        ll U;
        cin>>U;
        cout<<sum(r,n-l+1,U)<<'\n';
    }

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

