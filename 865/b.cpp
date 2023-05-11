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
    int a[2][n];
    int ctr1 = 1;
    int ctr2 = 2*n;
    for(int i=0;i<n;i++){
        if(i%2==0){
            a[1][(i-1+n)%n] = ctr2--;
            a[0][i] = ctr2--;
        }else{
            a[0][i] = ctr1++;
            a[1][(i-1+n)%n] = ctr1++;
        }
    }


    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<' ';
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

