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

    if(k>=26){
        for(int i=0;i<s.length();i++){
            cout<<'a';
        }
        cout<<'\n';
        return;
    }


    vector<int> g(26,0);

    for(int i=0;i<26;i++){
        g[i] = i;
    }

    int last = -1;

    vi to;
    for(int i=0;i<n;i++){
        if(s[i]-'a' > last){
            last = s[i]-'a';
            to.pb(i);
        }
    }


    for(int i =0;i<to.size();i++){
        int cur = s[to[i]]-'a';

        while(cur!=0 && k>0){
            if(g[cur]!=cur){
                break;
            }

            g[cur] = cur-1;
            cur--;
            k--;
        }
    }
    string ans;

    for(int i=0;i<n;i++){
        int cur = s[i]-'a';

        while(g[cur]!=cur){
            cur = g[cur];
        }

        ans+=(cur+'a');
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

