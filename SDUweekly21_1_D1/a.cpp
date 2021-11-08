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
struct Matrix{
    ll a[2][2];
};


Matrix mult(Matrix a, Matrix b){
    Matrix ret;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ret.a[i][j] = 0;

            for(int k=0;k<2;k++){
                ret.a[i][j] = (ret.a[i][j] + a.a[i][k] * b.a[k][j])%MOD;
            }
        }
    }

    return ret;
}


Matrix binPow(Matrix a, ll b){
    if(b==1){
        return a;
    }
    if(b%2==0){
        Matrix ret;

        ret = binPow(a,b/2);

        return mult(ret,ret);
    }else{
        return mult(a,binPow(a,b-1));
    }
}

void solve() {
    ll n;
    cin>>n;
    Matrix mat;
    mat.a[0][0] = 19;
    mat.a[0][1] = 7;
    mat.a[1][0] = 6;
    mat.a[1][1] = 20;


    Matrix ans = binPow(mat,n);

    cout<<ans.a[0][0]%MOD<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

