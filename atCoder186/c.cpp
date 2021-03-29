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
bool check(int x){
    int tmp = x;
    while(tmp!=0){
        if(tmp%10==7){
            return false;
        }
        tmp/=10;
    }
    tmp = x;
    while(tmp!=0){
        if(tmp%8==7){
            return false;
        }
        tmp/=8;
    }

    return true;
}


void solve() {
    int n;
    cin>>n;
    int ctr = 0;
    for(int i=1;i<=n;i++){
        if(check(i)) ctr++;
    }
    cout<<ctr<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

