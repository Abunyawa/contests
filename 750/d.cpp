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
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n%2==0){
        for(int i=0;i<n;i+=2){
            ll div = __gcd(a[i],a[i+1]);
            cout<<a[i+1]/div<<' '<<(-1*a[i])/div<<' ';
        }

        cout<<'\n';
    }else{
        for(int i=0;i<n-3;i+=2){
            ll div = __gcd(a[i],a[i+1]);
            cout<<a[i+1]/div<<' '<<(-1*a[i])/div<<' ';
        }
        if(a[n-3]!=-a[n-2]){
            ll mltp = (-1)*a[n-1];
            ll z = -(a[n-3]*mltp + a[n-2]*mltp)/a[n-1];

            cout<<mltp<<' '<<mltp<<' '<<z;
            cout<<'\n';
        }else{
            if(a[n-3]!=-a[n-1]){
                ll mltp = (-1)*a[n-2];
                ll z = -(a[n-3]*mltp + a[n-1]*mltp)/a[n-2];

                cout<<mltp<<' '<<z<<' '<<mltp;
                cout<<'\n';
            }else{
                ll mltp = (-1)*a[n-3];
                ll z = -(a[n-2]*mltp + a[n-1]*mltp)/a[n-3];

                cout<<z<<' '<<mltp<<' '<<mltp;
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

