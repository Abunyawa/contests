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

vl dp(1000,-1);


void solve() {
    int x;
    cin>>x;
    cout<<dp[x]<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<(1<<10);i++){
        ll num = 0;
        int sm = 0;
        for(int j = 0;j<=9;j++){
            if(i&(1<<j)){
                num*=10;
                num+=j;
                sm+=j;
            }
        }
        if(dp[sm]==-1){
            dp[sm] = num;
        }else{
            dp[sm] = min(dp[sm],num);
        }
        
    }

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

