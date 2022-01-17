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
ll binPow(ll a, ll p){
    if(p==0){
        return 1LL;
    }else if(p==1){
        return a%MOD;
    }else{
        if(p%2==0){
            ll res = binPow(a,p/2);

            return (res*res)%MOD;
        }else{
            return (a*binPow(a,p-1))%MOD;
        }
    }
}
/*
(2x+n-1)*(n/2) == (2y+m-1)*(m/2)

(2x+n-1)/(2y+m-1) == m/n

2xn + n^2 - n = 2ym + m^2 - m
2(xn-ym) = m^2-n^2 -m + n
2(xn-ym) = m*(m-1) - n(n-1)
2xn = m*(m-1) - n(n-1)+2ym
x = (m*(m-1)-n(n-1))/2n + ym/n


*/
void solve() {
    int n;
    cin>>n;

    vl a(n);
    ll odd = 0;
    ll even = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            even++;
        }else{
            odd++;
        }
    }
    // (2^odd - 1) * (2^even) 
    ll ans = (binPow(2,n))%MOD;

    ans -= binPow(2,even);
    if(ans<0){
        ans+=MOD;
    }


    sort(all(a));
    map<ll,int> m;
    ll pairs = 0;
    ll bad = 0;
    map<ll,bool> badC;
    for(int i=n-1;i>=0;i--){
        if(a[i]%2==0){
            //debug(a[i]);
            bool flag = false;
            for(ll cur = a[i];cur<=1e9;cur*=3LL){
                //debug(cur);
                if(m[cur]>0){
                    flag = true;
                    if(badC[cur]==true){
                        bad--;
                        badC[cur]=false;
                    }
                    pairs+=m[cur];
                }
            }

            if(!flag){
                bad++;
                badC[a[i]] = true;
            }
            m[a[i]]++;
        }
    }

    //debug(pairs);
    ans= (ans+(pairs*binPow(2,even-2))%MOD)%MOD;
    //debug(ans);
    cout<<ans<<'\n';
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

