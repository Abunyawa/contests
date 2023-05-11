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
    string s;
    cin>>s;
    int n = s.length();
    int ans = 0;
    if(n==1){
        if(s[0]=='^'){
            cout<<1<<'\n';
            return;
        }else{
            cout<<2<<'\n';
            return;
        }
    }

    if(s[0]=='_'){
        ans++;
    }

    if(s[n-1]=='_'){
        ans++;
    }
    for(int i=0;i<n-1;i++){
        if(s[i]=='_'){
            if(s[i+1]!='^'){
                ans++;
            }
        }
    }    

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

