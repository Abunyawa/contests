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
    s = " "+s;
    vector<vi> pref(n+1,vi(10,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){
            pref[i][j] = pref[i-1][j];
        }

        pref[i][s[i]-'0']++;
    }
    int ans = 0;
    for(int k=1;k<=100;k++){
        for(int i=1;i+k-1<=n;i++){
            int nl = 0;
            int mx = 0;
            for(int j=0;j<10;j++){
                int have = pref[i+k-1][j] - pref[i-1][j];
                mx = max(mx, have);
                if(have!=0){
                    nl++;
                }
            }

            if(mx<=nl){
                ans++;
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
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

