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

int ask(int x){
    cout<<"? "<<x<<endl;
    int ret;
    cout.flush();
    cin>>ret;
    return ret;
}

void solve() {
    int n;
    cin>>n;
    
    vector<int> ans(n+1, 0);

    for(int i=1;i<=n;i++){
        if(ans[i]!=0){
            continue;
        }

        while(ask(i)!=i){

        }
        int cur = i;
        while(true){
            int x = ask(i);
            ans[cur] = x;
            cur = x;
            if(cur==i){
                break;
            }
        }      
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }

    cout<<endl;
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

