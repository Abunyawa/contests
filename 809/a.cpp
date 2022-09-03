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
    int n,m;
    cin>>n>>m;
    vi a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<char> s(m, 'B');

    for(int i=0;i<n;i++){
        int cur = a[i];
        int alt = m+1-a[i];
        if(s[min(cur,alt)-1] != 'A'){
            s[min(cur,alt)-1] = 'A';
        }else{
            s[max(cur,alt)-1] = 'A';
        }
    }

    for(int i=0;i<m;i++){
        cout<<s[i];
    }
    cout<<'\n';
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

