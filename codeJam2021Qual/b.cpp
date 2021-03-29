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
    int x,y;
    cin>>x>>y;
    string s;
    cin>>s;
    int n = s.length();
    char prev = '0';
    int len = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(s[i]=='?'){
            len++;
            if(i-1>=0 && s[i-1]!='?'){
                prev = s[i-1];
            }
        }else{
            if(i-1>=0 && s[i-1]!='?'){
                if(s[i-1]!=s[i]){
                    if(s[i-1]=='C'){
                        ans+=x;
                    }else{
                        ans+=y;
                    }
                }
            }
            if(len!=0){ 
                if(prev!='0'){
                    if(prev!=s[i]){
                        if(prev=='C'){
                            ans+=x;
                        }else{
                            ans+=y;
                        }
                    }
                }
            }
            len = 0;
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
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

