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
    int n,m;
    cin>>n>>m;

    vi x(n);
    set<int> a;
    int l = 0;
    int r = 0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        if(x[i]>0){
            a.insert(x[i]);
        }else{
            if(x[i]==-1){
                l++;
            }else{
                r++;
            }
        }
    }

    vi s;
    for(auto x: a){
        s.pb(x);
    }

    int ans = 0;
    sort(all(s));
    for(int i=0;i<s.size();i++){
        int loc = s.size();

        int freeL = s[i] - 1 - i;
        int freeR = m-s[i] - (s.size()-i-1);
        // debug(freeL);
        // debug(i);
        // debug(s[i]);
        loc += min(freeL,l) + min(freeR, r);

        ans = max(ans, loc);
    }
    //cout<<ans<<'\n';
    ans = max(ans, min(m,l+(int)s.size()));
    ans = max(ans, min(m,r+(int)s.size()));
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

