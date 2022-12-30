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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}

bool check(ll a, ll b){
    ll nm = a;
    ll have = 1;

    do{
        have *= nm%10;
        nm/=10;
    }while(nm!=0);

    return (have*a)==b;
}

void solve() {
    int n;
    ll f;
    cin>>n>>f;
    ll st = pow(10,n-1);
    if(n==1){
        st = 0;
    }
    for(ll i=st;i<pow(10, n);i++){
        if(check(i,f)){
            cout<<i<<'\n';
            return;
        }
    }

    cout<<-1<<'\n';
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

