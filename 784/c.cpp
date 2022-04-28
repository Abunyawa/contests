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
    int n;
    cin>>n;
    int evev = 0;
    int evod = 0;
    int odev = 0;
    int odod = 0;

    for(int i =0 ;i<n;i++){
        int x;
        cin>>x;
        if(i%2==0){
            if(x%2==0){
                evev++;
            }else{
                evod++;
            }
        }else{
            if(x%2==0){
                odev++;
            }else{
                odod++;
            }
        }
    }

    if((evev==0 || evod == 0) && (odev==0 || odod == 0)){
        yes();
    }else{
        no();
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

