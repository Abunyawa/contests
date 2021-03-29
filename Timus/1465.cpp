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

vi grandi(1000,-1);

int mex(vector<int> a) {
	set<int> b(a.begin(), a.end());
	for (int i=0; ; ++i)
		if (!b.count(i))
			return i;
}

int gr(int n){
    if(grandi[n] == -1){
        vi a;
        a.pb(gr(n-2));
        for(int i=2;i<n;i++){
            a.pb(gr(i-2) ^ gr(n-i-1));
        }
        grandi[n] = mex(a);
    }

    return grandi[n];
}

void solve() {
    int n;
    cin>>n;
    grandi[0] = 0;
    grandi[1] = grandi[2] = 1;
    int ans = gr(n%(2*68));
    if(ans!=0){
        cout<<"White\n";
    }else{
        cout<<"Black\n";
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

