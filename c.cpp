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
    ll n,x,p;
    cin>>n>>x>>p;
    ll stx = x;
    vi a(n,0);
    a[x] = 0;
    for(int i=1;i<=min(n,p);i++){
        x = (x+i)%n;
        a[x] = 1;
    }

    if(p<=n){
        if(a[0]!=1){
            no();
            return;
        }else{
            yes();
            return;
        }
    }

    if(a[0] == 1){
        yes();
        return;
    }

    ll df = ((1+n)*n/2)%n;

    if(df==0){
        if(stx!=0){
            no();
            return;
        }else{
            yes();
            return;
        }
    }

    ll have = p/n;
    ll cur = 0;
    vector<bool> was(n,false);
    was[0] = true;
    for(int i=1;i<have;i++){
        cur = (cur-df);
        if(cur<0){
            cur+=n;
        }
        if(was[cur]){
            break;
        }
        was[cur] = true;
        if(a[cur]==1){
            yes();
            return;
        }
    }

    ll free = p%n;

    x = (stx+df*have)%n;

    for(int i=1;i<=free;i++){
        x = (x+i)%n;
        if(x==0){
            yes();
            return;
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

