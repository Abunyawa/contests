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

const ll INF = 1e16;

void solve() {
    ll x,n;
    cin>>x>>n;


    pair<ll,ll> pos[2][2];
    pos[0][0] = {INF,INF};
    pos[1][1] = {INF,INF};
    pos[0][1] = {INF,INF};
    pos[1][0] = {INF,INF};


    pos[abs(x%2)][1] = {x, 1};

    ll cur = 1;

    while(cur<=n){
        if(x%2==0){
            x-=cur;
            cur++;
        }else{
            x+=cur;
            cur++;
        }
        if(cur>n){
            break;
        }
        if(pos[abs(x%2)][cur%2].fi==INF){
            pos[abs(x%2)][cur%2] = {x,cur};
        }else{
            ll d = x - pos[abs(x%2)][cur%2].fi;
            ll mv = cur - pos[abs(x%2)][cur%2].se;
            ll left = n - cur;
            ll totD = (left/mv)*d;

            cur += left/mv * mv;
            x += totD;
        }
    }

    for(ll i = cur;i<=n;i++){
        if(x%2==0){
            x-=cur;
            cur++;
        }else{
            x+=cur;
            cur++;
        }
    }

    cout<<x<<'\n';
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

