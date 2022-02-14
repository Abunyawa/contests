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
    int n,k;
    cin>>n>>k;


    if(k==1){
        yes();

        for(int i=1;i<=n;i++){
            cout<<i<<'\n';
        }
        return;
    }

    if(n%2==1){
        no();
    }else{
        yes();
        int ev = 2;
        int od = 1;
        for(int i=1;i<=n;i++){
            if(i%2==1){
                for(int j = 0;j<k;j++, od+=2){
                    cout<<od<<' ';
                }
                cout<<'\n';
            }else{
                for(int j = 0;j<k;j++, ev+=2){
                    cout<<ev<<' ';
                }
                cout<<'\n';

            }
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








