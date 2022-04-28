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
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    vi ans(n,0);
    int cur = 0;

    for(int i = 0;i<n-1;i++){
        
        if(cur==1){
            if(s[i]=='1'){
                s[i] = '0';
            }else{
                s[i] = '1';
            }
        }
        if(k==0){
            continue;
        }

        if(s[i]=='1'){
            if(k%2==0){
                continue;
            }else{
                ans[i]++;
                k--;
                cur^=1;
            }
        }else{
            if(k%2==0){
                s[i]='1';
                ans[i]++;
                k--;
                cur^=1;
            }else{
                s[i]='1';
                continue;
            }
        }
    }
    if(cur==1){
        if(s[n-1]=='1'){
            s[n-1] = '0';
        }else{
            s[n-1] = '1';
        }
    }

    if(k!=0){
        if(k%2==0){
            ans[n-1]+=k;
        }else{
            ans[n-1]+=k;
        }
    }

    cout<<s<<'\n';
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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

