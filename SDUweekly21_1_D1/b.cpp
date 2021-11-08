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
    ll a[3][3];
};


void solve() {
    ll n;
    cin>>n;
    Matrix mat;
    Matrix a;
    mat.a[0][0] = 1;
    mat.a[0][1] = 1;
    mat.a[0][2] = 0;

    mat.a[1][0] = 1;
    mat.a[1][1] = 0;
    mat.a[1][2] = 0;

    mat.a[2][0] = 0;
    mat.a[2][1] = 1;
    mat.a[2][2] = 0;
   
    a.a[0][0] = 0;
    a.a[0][1] = 0;
    a.a[0][2] = 0;

    a.a[1][0] = 0;
    a.a[1][1] = 0;
    a.a[1][2] = 0;

    a.a[2][0] = 0;
    a.a[2][1] = 0;
    a.a[2][2] = 0;

    a.a[0][0] = 1;
    a.a[1][1] = 1;
    a.a[2][2] = 1;

    if(n<3){
        if(n==0){
            cout<<0<<'\n';
        }else{
            cout<<1<<'\n';
        }
        return;
    }
    Matrix tmp;

    n-=2;
    while(n) {
		if(n % 2) {
            for(int i=0;i<3;i++){
                for(int j =0;j<3;j++){
                    tmp.a[i][j] = 0;

                    for(int k=0;k<3;k++){
                        tmp.a[i][j] = (tmp.a[i][j] + a.a[i][k] * mat.a[k][j])%MOD;
                    }
                }
            }
            a = tmp;
		}
		n /= 2;

        for(int i=0;i<3;i++){
            for(int j =0;j<3;j++){
                tmp.a[i][j] = 0;

                for(int k=0;k<3;k++){
                    tmp.a[i][j] = (tmp.a[i][j] + mat.a[i][k] * mat.a[k][j])%MOD;
                }
            }
        }
        mat = tmp;
	}

    cout<<(a.a[0][0] + a.a[0][1])%MOD<<'\n';
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

