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
    int mx = 0;
    map<char,int> m;
    while(cin>>s){
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ' && s[i]!='\n'){
                m[s[i]]++;
                if(m[s[i]]>mx){
                    mx = m[s[i]];
                }
            }
        }
    }

    for(int i=mx;i>0;i--){
        for(auto x: m){
            if(x.se >= i){
                cout<<"#";
            }else{
                cout<<" ";
            }
        }
        cout<<'\n';
    }

    for(auto x: m){
        cout<<x.fi;     
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
