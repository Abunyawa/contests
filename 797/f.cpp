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

ll lcm(ll a, ll b){
    return (a*b)/__gcd(a,b);
}

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}


void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = "+"+s;
    vl p(n+1);

    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    vector<bool> used(n+1,false);
    vector<vl> cycles;

    for(int i=1;i<=n;i++){
        if(used[i]) continue;

        int cur = i;

        vl c;

        while(!used[cur]){
            c.pb(cur);
            used[cur] = true;
            cur = p[cur];
        }

        cycles.pb(c);
    }

    vector<string> ss;

    for(int i=0;i<cycles.size();i++){
        string loc = "";

        for(int j=0;j<cycles[i].size();j++){
            loc+=s[cycles[i][j]];
        }
        ss.pb(loc);
    }

    vl cc;
    for(int i=0;i<ss.size();i++){
        string cur = ss[i];

        vi pref = prefix_function(cur);
        int k = cur.length()-pref[cur.length()-1];
        if(cur.length()%k==0){
            cur = cur.substr(0,k);
        }

        ss[i] = cur;
        cc.pb(cur.length());
    }

    if(cc.size()<=1){
        cout<<cc[0]<<'\n';
        return;
    }else{
        ll ans = lcm(cc[0],cc[1]);

        for(int i=2;i<cc.size();i++){
            ans = lcm(ans,cc[i]);
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

