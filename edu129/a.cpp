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

    vi a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int m;
    cin>>m;
    vi b(m);

    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(all(a));
    sort(all(b));

    if(a[n-1]>b[m-1]){
        cout<<"Alice\nAlice\n";
    }else if(a[n-1]<b[m-1]){
        cout<<"Bob\nBob\n";
    }else{
        cout<<"Alice\nBob\n";
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

