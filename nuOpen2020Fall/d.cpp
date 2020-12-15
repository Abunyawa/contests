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
typedef pair<ll, ll> pll;


const ll MOD = 1e9+7;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll p[20][20];
ll powM(ll a, ll p){
    if(p==0){
        return 1;
    }
    if(p==1){
        return a;
    }
    if(p%2==0){
        ll tmp = powM(a,p/2);
        return (tmp*tmp)%MOD;
    }else{
        return a*powM(a,p-1)%MOD;
    }
}
ll fact(int n){
    ll ret = 1;
    for(int i=2;i<=n;i++){
        ret = (ret*i)%MOD;
    }
    return ret;
}

/*


1 1 1 1 1

*/
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    }

    ll den = 0;
    int n2 = n;
    while(n2!=0){
        n2/=2;
        den++;
    }

    vector<vector<pll>> stage[den];
    for(int j = 0;j<n;j++){
        vector<pll> loc;
        for(int i=0;i<n;i++){
            loc.pb({i,1});
        }
        stage[0].pb(loc);
    }
    for(int st = 1;st<den;st++){
        for(int i=0;i<stage[st-1].size();i+=2){
            vector<pll> loc;
            vector<ll> prob(n,0);
            for(auto x: stage[st-1][i]){
                ll mat = 0;
                for(auto y: stage[st-1][i+1]){
                    mat += y.se*p[x.fi][y.fi];
                    mat%=MOD;
                }
                prob[x.fi] += x.se*mat;
                prob[x.fi]%=MOD;
            }
            for(auto x: stage[st-1][i]){
                ll mat = 0;
                for(auto y: stage[st-1][i+1]){
                    mat += y.se*p[x.fi][y.fi];
                    mat%=MOD;
                }
                prob[x.fi] += x.se*mat;
                prob[x.fi]%=MOD;
            }
            for(int k=0;k<n;k++){
                loc.pb({k,prob[k]%MOD});    
            }
            stage[st].pb(loc);
        }
    }
    vector<ll> nums(n);
    vector<ll> ans(n);
    
    for(auto x: stage[den-1][0]){
        nums[x.fi] += (1LL * x.se)%MOD; 
    }
    for(int i=0;i<n;i++){
        ll num = nums[i]%MOD;
        ll den1 = (powM(100,den-1)*powM(n,powM(2,n-1)-1))%MOD;
        cout<<num<<'/'<<den1<<'\n'; 
        ll gcd = __gcd(num,den1);
        num/=gcd;
        den1/=gcd;
        ans[i] = (num%MOD * powM(den1,MOD-2))%MOD;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        //solve();
    }
    

    return 0;
}

