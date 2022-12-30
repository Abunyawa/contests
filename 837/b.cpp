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



vector<int> t;
int n;

const int INF = -1000*1000*1000;

void init (int nn)
{
	n = nn;
	t.assign (n, INF);
}

int getmax (int r)
{
	int result = INF;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result = max (result, t[r]);
	return result;
}

void update (int i, int new_val)
{
	for (; i < n; i = (i | (i+1)))
		t[i] = max (t[i], new_val);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		update (i, a[i]);
}

void solve() {
    int n,m;
    cin>>n>>m;

    init(n+1);
    for(int i = 0;i<=n;i++){
        update(i, 0);
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        update(max(x,y), min(x,y));
    }

    ll ans = 0;

    for(int i=n;i>0;i--){
        ll pos = getmax(i)+1;
        //cout<<pos<<'\n';
        ans += i-pos+1;
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

