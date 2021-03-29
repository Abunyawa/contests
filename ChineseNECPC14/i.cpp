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
    int n,h,H;
    cin>>n>>h>>H;
    vi x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vi c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    vector<pii> g;
    for(int i=0;i<n;i++){
        int pos = 0;
        int tms = x[i]/H;
        int th = x[i]%H;
        if(tms%2==0){
            pos+=th;
        }else{
            pos = H-th;
        }

        if(pos<=h){
            g.pb({x[i]+c[i],i});
        }else{
            if(tms%2==0){
                g.pb({x[i]+(H-pos)+(H-h)+c[i],i});
            }else{
                g.pb({x[i]+pos-h+c[i],i});
            }
        }
    }

    sort(all(g));

    cout<<g[0].se+1<<'\n';

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

