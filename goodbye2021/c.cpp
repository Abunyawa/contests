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
    vector<double> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = n-1;
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            //cout<<"h"<<endl;
            double dif = (a[j] - a[i])/(double)(j-i);

            if(dif*(double)(j-i) != (a[j] - a[i])){
                continue;
            }
            int locA = 0;
            for(int k = i+1;k<n;k++){
                if(a[k]!=a[i]+dif*(double)(k-i)){
                    locA++;
                }
            }
            //cout<<"b"<<endl;
            for(int k = i-1;k>=0;k--){
                if(a[k] != a[i]-dif*(double)(i-k)){
                    locA++;
                }
            }
            //cout<<locA<<' '<<i<<' '<<j<<endl;
            ans = min(locA,ans);
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

