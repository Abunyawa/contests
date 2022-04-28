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
    vi c(3);
    vi m(3);
    vi y(3);
    vi k(3);
    for(int i =0;i<3;i++){
        cin>>c[i]>>m[i]>>y[i]>>k[i];
    }

    sort(all(c));
    sort(all(m));
    sort(all(y));
    sort(all(k));

    int sm = c[0]+m[0]+k[0]+y[0];

    if(sm<1000000){
        cout<<"IMPOSSIBLE\n";
    }else{
        int ex = sm-1000000;
        
        int tmp = min(c[0],ex);
        c[0] = c[0]-tmp;
        ex -= tmp;

        tmp = min(m[0],ex);
        m[0]-=tmp;
        ex -= tmp;

        tmp = min(y[0],ex);
        y[0]-=tmp;
        ex -= tmp;
        
        tmp = min(k[0],ex);
        k[0]-=tmp;
        ex -= tmp;

        cout<<c[0]<<' '<<m[0]<<' '<<y[0]<<' '<<k[0]<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    cin>>tt;
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

