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
    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    } 

    int d[n][33];

    for(int i=0;i<n;i++){
        for(int j=0;j<33;j++){
            d[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        int ctr = 0;
        while(a[i]!=0){
            d[i][ctr] = a[i]%2;
            a[i]/=2;
            ctr++;
        }
    }

    for(int bit = 32;bit>=0;bit--){
        int ctr = 0;
        for(int i=0;i<n;i++){
            if(d[i][bit]==1){
                ctr++;
            }
        }

        if(ctr%2==0){
            continue;
        }else{
            for(int i=0;i<n;i++){
                
            }
        }
    }
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

