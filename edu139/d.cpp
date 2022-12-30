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
int tox[] = {0,0,1,-1};
int toy[] = {1,-1,0,0};
const int N = (int) 1e7;

vi primes;
int used[N];

void solve() {
    int x,y;
    cin>>x>>y;

    if(__gcd(x,y)!=1){
        cout<<0<<'\n';
        return;
    }

    if(x%2==y%2){
        cout<<1<<'\n';
        return;
    }

    if(abs(x-y)==1){
        cout<<-1<<'\n';
        return;
    }

    int dif = abs(x-y);
    int ans = used[dif]-x%used[dif];

    while(dif!=1){
        ans=min(ans, used[dif]-x%used[dif]);
        dif/=used[dif];
    }

    cout<<ans<<'\n';
    return;
    
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; ++i) {
        if(!used[i]) {
            primes.push_back(i);
            for (int j = i; j < N; j += i){
                if(used[j]==0){
                    used[j] = i;
                    continue;
                }
                used[j] = min(used[j],i);
            }
        }
    }
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

