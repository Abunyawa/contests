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


    char d[2][n];
    int l = 0;
    int r = 0;
    int ctrU = 0;
    int ctrD = 0;
    for(int i=0;i<2;i++){
        for(int j = 0;j<n;j++){
            cin>>d[i][j];
            if(d[i][j]=='*'){
                l = min(l,j);
                r = max(r,j);

                if(i==0){
                    ctrU++;
                }else{
                    ctrD++;
                }
            }
        }
    }


    cout<<r-l+min(ctrU,ctrD)<<'\n';
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

