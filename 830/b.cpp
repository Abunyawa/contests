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

    int cur = 0;
    int ans =0;
    for(int i=1;i<n;i++){
        int x = s[i]-'0';
        if(cur%2==1){
            x^=1;
        }

        if(x>=(s[i-1]-'0')){
            s[i] = x+'0';
            continue;
        }else{
            ans++;
            cur^=1;
            s[i] = x^1 +'0';
        }
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

