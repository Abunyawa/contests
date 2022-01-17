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


const ll MOD = 1e9+7;



ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

void solve() {
    int n,m, xs, ys, xf, yf, p;
    cin>>n>>m>>xs>>ys>>xf>>yf>>p;

    int curx = xs, cury = ys, dx = 1, dy = 1;

    vi st;
    int ctr = 0;

    ll ans = 0;
    
    while(true){
        if(curx==xf || cury==yf){
            ll pr = ((ctr * p)%MOD * powM(100LL-p,st.size()))%MOD;
            ll q = powM(100LL,st.size()+1); 
            ll loc = (pr * powM(q,MOD-2))%MOD;
            ans = (ans+loc)%MOD;
            st.pb(ctr);

        }
        

        if(curx==xs && cury == ys && dx==1 && dy==1 && ctr!=0){
            break;
        }

        if(curx+dx<=0 || curx+dx>n){
            dx = -dx;
        }
        

        if(cury+dy<=0 || cury+dy>m){
            dy = -dy;
        }

        if(curx==xs && cury == ys && dx==1 && dy==1 && ctr!=0){
            break;
        }

        curx+=dx;
        cury+=dy;
        ctr++;
    }
    
    cout<<ans<<endl;
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

