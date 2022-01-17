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

int n;
vi a;
vi b;

bool f(int need){
    int tar = need;
    int cur = 0;
    for(int i=0;i<n;i++){
        /*
        debug(a[i]);
        debug(need);
        debug(cur);
        */
        if(a[i]>=need-1 && b[i]>=cur){
            cur++;
            need--;
        }
    }

    return cur >= tar;
}


void solve() {
    cin>>n;
    a.resize(n);
    a.clear();
    b.resize(n);
    b.clear();
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    int l = 1;
    int r = n+1;
    while(l<r-1){
        int m = (l+r)/2;
        //debug(m);
        if(f(m)){
            l = m;
        }else{
            r = m;
        }
    }


    cout<<l<<'\n';
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

