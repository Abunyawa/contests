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
    ll n,k;
    cin>>n>>k;

    if(k%2==1){
        yes();
        for(int i=1;i<=n;i+=2){
            cout<<i<<' '<<i+1<<'\n';
        }
    }else{
        if(k%4==2 || k%4==3){
            yes();
            for(int i=4;i<=n;i+=4){
                cout<<i-1<<' '<<i<<'\n';
            }

            for(int i=1;i<=n;i+=4){
                if(k%4==2){
                    cout<<i+1<<' '<<i<<'\n';
                }else{
                    cout<<i<<' '<<i+1<<'\n';
                }
            }
        }else{
            no();
        }
    }
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

