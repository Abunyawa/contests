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
    vl l(3);
    cin>>l[0]>>l[1]>>l[2];

    sort(all(l));

    if(l[0]==l[1]){
        if(l[2]%2==0){
            yes();
        }else{
            no();
        }
    }else if(l[1]==l[2]){
        if(l[0]%2==0){
            yes();
        }else{
            no();
        }
    }else{
        if(l[2]==l[0]+l[1]){
            yes();
        }else{
            no();
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

