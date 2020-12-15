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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int a[6];
    int b[6];
    for(int i=0;i<6;i++){
        cin>>a[i];
    }
    for(int i=0;i<6;i++){
        cin>>b[i];
    }
    int tot = 6*6;
    int win = 0;
    for(int i=0;i<6;i++){
        for(int j = 0;j<6;j++){
            if(a[i]>b[j]) win++;
        }
    }
    int gcd = __gcd(win,tot);
    win/=gcd;
    tot/=gcd;
    cout<<win<<'/'<<tot<<'\n';

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

