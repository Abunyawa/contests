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

    string frs;
    frs = "..";
    string ev = "+-";
    string sec = "..";
    string od = "|.";
    for(int i = 2;i<m*2+1;i++){
        frs+=(i%2==0)?"+":"-";
        ev+=(i%2==0)?"+":"-";

        sec+=(i%2==0)?"|":".";
        od+=(i%2==0)?"|":".";
    }

    cout<<frs<<'\n';
    cout<<sec<<'\n';

    for(int i =2;i<2*n+1;i++){
        string p = (i%2==0)?(ev):(od);
        cout<<p<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": \n";
        solve();
    }

    return 0;
}

