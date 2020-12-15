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
    vector<vi> row(n,vi(10,0));
    vector<vi> col(n,vi(10,0));
    int d[n][n];
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            int nm = x-'0';
            d[i][j] = nm;
            row[i][nm]++;
            col[j][nm]++;
        }
    }
    vi rightmost(10,-1);
    vi leftmost(10,n+1);
    vi upper(10,-1);
    vi lower(10,n+1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rightmost[d[i][j]] = max(rightmost[d[i][j]],j);
            leftmost[d[i][j]] = min(leftmost[d[i][j]],j);
            lower[d[i][j]] = min(lower[d[i][j]],i);
            upper[d[i][j]] = max(upper[d[i][j]],i);
        }
    }
    vi ans(11,0);
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            int base = max(n-i-1,i);
            ans[d[i][j]] = max(ans[d[i][j]],base*(abs(j-rightmost[d[i][j]])));
            ans[d[i][j]] = max(ans[d[i][j]],base*(abs(j-leftmost[d[i][j]])));
            base = max(n-j-1,j);
            ans[d[i][j]] = max(ans[d[i][j]],base*(abs(i-upper[d[i][j]])));
            ans[d[i][j]] = max(ans[d[i][j]],base*(abs(i-lower[d[i][j]])));
        }
    }

    for(int i=0;i<10;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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

