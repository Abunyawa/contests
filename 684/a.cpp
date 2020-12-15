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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,c0,c1,h;
    cin>>n>>c0>>c1>>h;
    string s;
    cin>>s;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(c0+h<c1){
            if(s[i]=='1'){
                ans+=c0+h;
            }else{
                ans+=c0;
            }
        }else if(c1+h<c0){
            if(s[i]=='0'){
                ans+=c1+h;
            }else{
                ans+=c1;
            }
        }else{
            if(s[i]=='0'){
                ans+=c0;
            }else{
                ans+=c1;
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

