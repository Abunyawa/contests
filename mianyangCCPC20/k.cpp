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

const int MAXN = (int)1e5 + 5;

vector<pii> vec;
ll h[MAXN];
int n;

void solve() {
    /*
    cin >> n;
    
    rep (i, 1, n + 1) {
        cin >> h[i];
    }
    
    sort(h + 1, h + n + 1);
    
    for (int l = 1, r; l <= n; l = r) {
        r = l;
        
        while (r <= n && h[l] == h[r]) {
            ++r;
        }
        
        vec.eb(h[l], r - 1);
    }
    
    vec.eb((ll)2e9, n);
    ll mn = h[1], t = 0, ans = -1;
    
    rep (i, 0, sz(vec) - 1) {
        if (ans != -1) {
            break;
        }
        
        ll dur = vec[i + 1].fi - vec[i].fi;
        
        while (dur--) {
            rep (j, 0, vec[i].se) {
                t++;
                if (j == vec[i].se - 1) mn++;
                
                if (mn < t) {
                    ans = mn;
                    break;
                }
            }
        }
    }
    
    cout << ans << '\n';
    */
    
    ll n;
    cin>>n;
    if(n%2==1){
        if(n/2<=1){
            cout<<-1<<'\n';
            return;
        }
        cout<<1<<'\n';
    }else{
        if((n/2)%2==0){
            if(n/2-1<=1){
                cout<<-1<<'\n';
                return;
            }
            cout<<2<<'\n';
        }else{
            if(n/4<=1){
                cout<<-1<<'\n';
                return;
            }
            cout<<n/2 - n/4<<'\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;

    rep(i,1,tt+1) {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}