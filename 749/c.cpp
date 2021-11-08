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
    char d[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>d[i][j];
        }
    }

    vi bl(m+2,0);
    map<pii,int> ma;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(d[i-1][j]=='X' && d[i][j-1]=='X'){
                bl[j]++;
                bl[j-1]++;
                ma[{j-1,j}]++;
            }
        }
    }

    vi pref(m+2,0);

    for(int i=1;i<=m+1;i++){
        pref[i] = pref[i-1]+bl[i];
    }
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        int blocks = pref[y] - pref[x-1];
        blocks -= ma[{x-1,x}];
        blocks -= ma[{y,y+1}];

        if(blocks==0){
            yes();
        }else{
            no();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

