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


ll const MOD = 1e9+7;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = "0"+s;
    vi left(n+2,0);
    vi right(n+2,0);
    int cur = 0;
    int all = 0;
    
    for(int i=1;i<=n;i++){
        if(s[i]=='G'){
            all++;
            cur++;
            left[i] = cur;
        }else{
            left[i] = 0;
            cur = 0;
        }
    }
    cur = 0;
    int ans = 0;

    for(int i=n;i>0;i--){
        if(s[i]=='G'){
            cur++;
            right[i] = cur;
            ans = max(ans,cur);

        }else{
            right[i] = 0;
            cur = 0;
        }
    }

    for(int i=1;i<=n;i++){
        if(s[i]=='S'){
            if(left[i-1]+right[i+1]<all){
                ans = max(ans,left[i-1]+right[i+1]+1);
            }else{
                ans = max(ans,left[i-1]+right[i+1]);
            }
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

