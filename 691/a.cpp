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

    cout<<__gcd(__gcd(1+25,25+25),__gcd(121+25,169+25));
    /*
    int n,m;
    cin>>n>>m;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vl b(n);

    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    ll gcd = __gcd(a[0],a[min(n-1,1)]);
    for(int i = 2;i<n;i++){
        gcd = __gcd(gcd,a[i]);
    }
    for(int i=0;i<m;i++){
        if(b[i]%gcd!=0){
            cout<<1<<' ';
        }else{

        }
    }
    */
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

