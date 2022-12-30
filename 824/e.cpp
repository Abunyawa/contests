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

map<ll, vector<int>> g;

void solve() {
    g.clear();
    int n;
    cin>>n;

    vl a(n);
    vl b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            set<ll> res;
            res.insert(a[i]-b[j]);
            res.insert(b[j]+a[i]);

            for(ll x: res){
                g[x].pb(j);
            }
        }
    }

    int ctr = 0;
    for(auto x: g){
        cout<<x.fi<<' '<<x.se.size()<<endl;
        if(x.se.size()>=n){
            ll df = x.fi;
            vector<bool> used(n,false);

            vl h;
            for(int y: x.se){

                if(h.size()==n){
                    break;
                }

                if(used[y]){
                    continue;
                }
                ll da = a[h.size()];

                ll db = b[y];


                if(da+db==df){
                    if(da==df-db){
                        h.pb(da);
                    }else if(db-df==-da){
                        h.pb(-da);
                    }
                }else if(da-db==df){
                    if(df<=0){
                        h.pb(-da);
                    }else{
                        h.pb(da);
                    }
                }else{
                    continue;
                }

                used[y] = true;
            }

            if(h.size()==n){
                sort(all(h));
                ll add = 0;

                if(min(h[0],df)<0){
                    add = -min(h[0],df);
                }
                yes();

                for(int i=0;i<n;i++){
                    cout<<h[i]+add<<' ';
                }

                cout<<'\n';

                cout<<add<<' '<<add+df<<'\n';

                return;
            }

        }
    }

    no();
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

