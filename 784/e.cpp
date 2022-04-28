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
    vector<vl> ctr(26,vl(26,0));

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        ctr[s[0]-'a'][s[1]-'a']++;
    }

    ll ans = 0;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            
            for(int k = j+1;k<26;k++){
                ans+=ctr[j][i]*ctr[k][i];
            }
        }

    }

    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            
            for(int k = j+1;k<26;k++){
                ans+=ctr[i][j]*ctr[i][k];
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

