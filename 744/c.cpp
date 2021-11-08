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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    char d[n][m];
    int st[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
            st[i][j] = 0;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m-1;j++){
            if(d[i][j]=='*'){
                int ctr = 0;
                while(i-ctr>=0 && j-ctr>=0 && j+ctr<m && d[i-ctr][j+ctr]=='*' && d[i-ctr][j-ctr]=='*'){
                    ctr++;
                }
                //cout<<ctr<<'\n';
                if(ctr-1>=k){
                    for(int z = 0;z<ctr;z++){
                        st[i-z][j+z] = 1;
                        st[i-z][j-z] = 1;
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]=='*' && st[i][j]!=1){
                no();
                return;
            }
        }
    }

    yes();
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

