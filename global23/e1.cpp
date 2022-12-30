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

bool guess(int x){
    cout<<"! "<<x<<endl;

    string ans;
    cin>>ans;

    return ans == ": )";
}
bool ask(int l, int r){
    cout<<'? '<<(r-l+1)<<' ';
    for(int i=l;i<=r;i++){
        cout<<i<<' ';
    }

    cout<<endl;

    string ans;
    cin>>ans;

    return ans=="YES";
}

void solve() {
    int n;
    cin>>n;
    
    bool res = 1;
    if(ask(res)){
        return;
    }


    int l = 2;
    int r = n;

    while(l<r-1){
        bool ans;
        bool fr = ask(1,1);

        if(fr){
            int m = (l+r)/2;
            ans = ask(l,m);

            if(ans){
                r = m;
            }else{
                l = m+1;
            }
        }else{
            int m = (l+r)/2;
            bool ans1 = ask(l,m);
            bool ans2 = ask(l,m);

            if(ans1==ans2){
                if(ans1){
                    r = m;
                }else{
                    l = m+1;
                }
            }else{
                int loca         
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;

    while (tt--) {
        solve();
    }

    return 0;
}

