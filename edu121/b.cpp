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
    string s;
    cin>>s;
    int n = s.length();

    for(int i = n-2;i>=0;i--){
        if(s[i]-'0' + (s[i+1]-'0')>=10){
            int sm = s[i]-'0' + (s[i+1]-'0');
            s[i] = sm/10+'0';
            s[i+1] = sm%10+'0';
            cout<<s<<'\n';
            return;
        }
    }

    int sm = s[0]-'0' + (s[1]-'0');
    cout<<sm<<s.substr(2,n-1)<<'\n';

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

