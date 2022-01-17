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
    vi ok(n+1,0);
    vl fre;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;

        if(x>=1 && x<=n){
            if(ok[x]!=1){
                ok[x]++;
            }else{
                fre.pb(x);
            }
            
        }else{
            fre.pb(x);
        }
    }

    sort(all(fre));
    int ctr = 0;
    int ptr = 0;
    for(int i=1;i<=n;i++){
        if(ok[i]>0){
            continue;
        }

        if((fre[ptr]+1)/2>i){
            ptr++;
            ctr++;
        }else{
            cout<<-1<<'\n';
            return;
        }
    }

    cout<<ctr<<'\n';
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

