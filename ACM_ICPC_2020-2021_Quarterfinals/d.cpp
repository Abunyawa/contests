
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
    int n,w,h,s;
    cin>>n>>w>>h>>s;
    vector<char> let(n);
    int mx = 0;
    char letmx;
    vector<vi> ctr(n);
    for(int i=0;i<n;i++){
        cin>>let[i];
        for(int j = 0;j<h;j++){
            bool cur = 0;
            int ans  = 0;
            for(int k=0;k<w;k++){
                char x;
                cin>>x;
                if(x=='#'){
                    if(cur==0){
                        cur^=1;
                        ans++;
                    }
                }else{
                    if(cur==1){
                        cur^=1;
                        ans++;
                    }
                }
            }
            if(cur==1) ans++;
            if(ans>mx){
                mx = ans;
                letmx = let[i];
            }
            ctr[i].pb(ans);
        }
    }
    int num = (s+mx-1)/mx;
    for(int i=0;i<num;i++){
        cout<<letmx;
    }
    cout<<'\n';

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

