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
    int d[n][m];
    set<int> st[n];
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>d[i][j];
            st[i].insert(d[i][j]);
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans^=d[i][0];
    }
    if(ans!=0){
        cout<<"TAK\n";
        for(int i=0;i<n;i++){
            cout<<1<<' ';
        }
        cout<<'\n';
        return;
    }else{
        for(int i=0;i<n;i++){
            if(st[i].size()>1){
                for(int j = 1;j<m;j++){
                    if(d[i][j]!=d[i][0]){
                        cout<<"TAK\n";
                        for(int k = 0;k<n;k++){
                            if(k!=i){
                                cout<<1<<' ';
                            }else{
                                cout<<j+1<<' ';
                            }
                        }
                        cout<<'\n';
                        return;
                    }
                }
            }
        }
    }
    cout<<"NIE\n";

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

