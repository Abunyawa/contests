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
    ll n,k;
    ll x;
    cin>>n>>k>>x;
    string s;
    cin>>s;
    string ans = "";
    vi toK;
    vi sz;
    ll cur = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='*'){
            cur+=k;
        }else{
            if(cur!=0){
                sz.pb(cur+1);
            }

            cur = 0;
        }
    }
    if(cur!=0){
        sz.pb(cur+1);
    }
    int ptr = 0;
    reverse(all(sz));
    x--;
    while(x!=0){
        toK.pb(x%sz[ptr]);
        //cout<<x%sz[ptr]<<endl;
        x/=sz[ptr++];
    }

    ptr = 0;
    bool flag = false;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='a' && flag) {
            if(ptr<toK.size()){
                for(int j =0;j<toK[ptr];j++){
                    ans+='b';
                }
                ptr++;
            }
            ans+='a';
            flag = false;
        }else if(s[i]=='*'){
            flag = true;
        }else if(s[i]=='a'){
            ans+='a';
        }
    }

    if(flag){
        if(ptr<toK.size()){
            for(int j =0;j<toK[ptr];j++){
                ans+='b';
            }
            ptr++;
        }
    }


    reverse(all(ans));

    cout<<ans<<'\n';
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

