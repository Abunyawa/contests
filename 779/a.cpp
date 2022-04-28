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
    string s;
    cin>>s;
    int ans = 0;
    vi dv;
    int cur = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cur++;
        }else{
            if(i-1>=0 && i+1<n){
                if(s[i-1]=='0' && s[i+1]=='0'){
                    ans++;
                }
            }
            if(cur!=0){
                dv.pb(cur);
                cur = 0;
            }
        }
    }

    if(cur!=0){
        dv.pb(cur);
        cur = 0;
    }

    for(int i=0;i<dv.size();i++){
        ans+=(dv[i]-1)*2;
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

