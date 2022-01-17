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
x/u + y/v = (x+y)/(u+v)

x/u + y/v = (vx + uy) / uv

*/

void solve() {
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }


    sort(all(a));
    sort(all(b));
    for(int i=n-1;i>=0;i--){
        if(a[i]>b[i]){
            no();
            return;
        }else if(a[i]==b[i]){

        }else{
            if(b[i]-a[i]>1){
                no();
                return;
            }
        }
    }


    yes();
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

