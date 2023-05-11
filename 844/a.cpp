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
    int w,d,h;
    cin>>w>>d>>h;

    int a,b,f,g;

    cin>>a>>b>>f>>g;

    int ans1 = a + f + h + abs(b-g);
    int ans2 = w-a + w-f + h + abs(b-g);
    int ans3 = b + g + h + abs(a-f);
    int ans4 = d-b + d-g + h + abs(a-f);

    cout<<min(min(ans1,ans2), min(ans3,ans4))<<'\n';
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

