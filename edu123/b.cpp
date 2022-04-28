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

/*
4 3 2 1
1 4 3 2
2 1 4 3
3 2 1 4
*/

void solve() {
    int n;
    cin>>n;
    if(n==3){
        cout<<"3 2 1\n";
        cout<<"1 3 2\n";
        cout<<"3 1 2\n";
        return;
    }

    for(int i=n;i>0;i--){
        for(int j = 0;j<n;j++){
            int have = i-j;
            if(have<=0){
                have+=n;
            }
            cout<<have<<' ';
        }
        cout<<'\n';
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

