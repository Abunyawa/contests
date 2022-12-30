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
    int r[3],c[3];

    for(int i=0;i<3;i++){
        cin>>r[i]>>c[i];
    }
    int x,y;
    cin>>x>>y;

    int rw;
    if(r[0]==r[1]){
        rw = r[0];
    }else if(r[0]==r[2]){
        rw = r[0];
    }else{
        rw = r[1];
    }

    int cw;
    if(c[0]==c[1]){
        cw = c[0];
    }else if(c[0]==c[2]){
        cw = c[0];
    }else{
        cw = c[1];
    }

    if(cw%2!=y%2 && rw%2!=x%2){
        no();
    }else{
        if(cw%2==y%2){
            if(cw==y || (rw+1<=n && rw-1>0) || (cw+1<=n && cw-1>0)){
                yes();
                return;
            }
        }

        if(rw%2==x%2){
            if(rw==x || (rw+1<=n && rw-1>0) || (cw+1<=n && cw-1>0)){
                yes();
                return;
            }
        }

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

