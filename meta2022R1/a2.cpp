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

ll MOD = 1e9+7;

ll powM(ll a, ll b){
    if(b==0){
        return 1LL;
    }else if(b%2==1){
        return (a*powM(a,b-1))%MOD;
    }else{
        ll ret = powM(a,b/2);

        return (ret*ret)%MOD;
    }
}

void solve() {
    int n;
    ll k;
    cin>>n>>k;
    ll h1=0;
    ll h2=0;
    ll x=70000000;
    vl a(n);

    vl b(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        h1 = (h1+(a[i]*powM(x,i))%MOD)%MOD;
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
        h2 = (h2+(b[i]*powM(x,i))%MOD)%MOD;
    }



    for(int i=0;i<n;i++){
        //cout<<i<<' '<<h1<<' '<<h2<<'\n';
        if(h1==h2){
            bool good = true;
            for(int j=0;j<n;j++){
                if(a[j] != b[(i+j)%n]){
                    good = false;
                    break;
                }
            }

            if(good){
                if(n==2){
                    if(i==0){
                        if(k%2==0){
                            yes();
                            return;
                        }
                    }else{
                        if(k%2==1){
                            yes();
                            return;
                        }
                    }
                }else{
                    if(i==0){
                        if(k!=1){
                            yes();
                            return;
                        }
                    }else{
                        if(k>0){
                            yes();
                            return;
                        }
                    }
                }
            }
        }

        h2-=(b[i])%MOD;

        if(h2<0){
            h2+=MOD;
        }

        h2 = (h2 * powM(x,MOD-2))%MOD;

        h2 = (h2+(b[i]*powM(x,n-1))%MOD)%MOD;
    }

    no();
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

