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

    int ans = 0;

    int d[n][n];
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>d[i][j];
            a[i][j] = 0;
        }
    }
    int dx[] = {1,0,0,-1};
    int dy[] = {0,1,-1,0};

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i-1][j]%2==0){
                ans ^= d[i][j];
                for(int k =0;k<4;k++){
                    int tox = i + dx[k];
                    int toy = j +dy[k];

                    if(tox>=0 && tox<n && toy>=0 && toy < n){
                        a[tox][toy]++;
                    }
                }
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

