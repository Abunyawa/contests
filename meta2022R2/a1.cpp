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

int pr[1000100][26];


void solve() {
    string s;
    cin>>s;
    int n = s.length();

    s = " "+s;
    for(int i = 0;i<26;i++){
        pr[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            pr[i][j] = pr[i-1][j];
        }
        pr[i][s[i]-'a']++;
    }
    int q;
    cin>>q;
    int ans = 0;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        if((r-l+1)%2==0){
            continue;
        }

        int dif = 0;
        for(int j=0;j<26;j++){
            int left = pr[l+(r-l)/2-1][j] - pr[l-1][j];
            int right = pr[r][j] - pr[l+(r-l)/2-1][j];

            dif+=abs(left-right);
        }

        if(dif==1){
            //cout<<i<<'\n';
            ans++;
            continue;
        }
        dif = 0;

        for(int j=0;j<26;j++){
            int left = pr[l+(r-l)/2][j] - pr[l-1][j];
            int right = pr[r][j] - pr[l+(r-l)/2][j];

            dif+=abs(left-right);
        }

        if(dif==1){
            //cout<<i<<'\n';
            ans++;
            continue;
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
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

