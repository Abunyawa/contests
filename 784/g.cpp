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
    int n,m;
    cin>>n>>m;
    int rocks[n+1][m];
    char ans[n][m];
    char d[n][m];
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>d[i][j];
            rocks[i][j] = 0;
            ans[i][j] = '.';
        }
    }
    for(int i=0;i<m;i++){
        rocks[n][i]=0;
    }

    for(int j=0;j<m;j++){
        int cur = 0;

        for(int i=0;i<=n;i++){
            if(i==n){
                rocks[i][j] = cur;
            }else if(d[i][j]=='*'){
                cur++;
            }else if(d[i][j]=='o'){
                rocks[i][j] = cur;
                cur = 0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]=='o'){
                ans[i][j] = 'o';
                int pos = i-1;
                for(int k =0;k<rocks[i][j];k++){
                    ans[pos][j] = '*';
                    pos--;
                }
            }
        }
    }

    for(int j=0;j<m;j++){
        int pos = n-1;
        for(int k = 0;k<rocks[n][j];k++){
            ans[pos][j] = '*';
            pos--;
        }
    }

    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
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

