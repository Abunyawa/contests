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
    int n,p,q;

    cin>>n>>p>>q;
    string s;
    cin>>s;

    for(int i=0;i*p <= s.length();i++){
        int left = s.length()-i*p;

        if(left%q==0){
            int cur = 0;
            cout<<i+left/q<<'\n';
            for(int j = 0;j<i;j++){
                for(int k  =0;k<p;k++){
                    cout<<s[cur++];
                }
                cout<<'\n';
            }
            for(int j = 0;j<left/q;j++){
                for(int k = 0;k<q;k++){
                    cout<<s[cur++];
                }
                cout<<'\n';
            }
            return;
        }
    }  


    cout<<-1<<'\n';
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

