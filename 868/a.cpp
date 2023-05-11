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
    int n, k;
    cin>>n>>k;

    for(int i=0;i<=n;i++){
        int sm1 = i*(i-1)/2;
        int sm2 = (n-i)*(n-i-1)/2;
        if(sm1+sm2==k){
            yes();
            for(int j=0;j<i;j++){
                cout<<"1 ";
            }
            for(int j=0;j<n-i;j++){
                cout<<"-1 ";
            }
            cout<<'\n';
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

