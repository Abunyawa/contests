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
    string s;
    
    cin>>s;

    string t;
    cin>>t;
    reverse(all(t));
    map<string,int> p;
    for(int i=0;i<n;i++){

        string pr = "";

        pr += (char)(min(s[i]-'a',t[i]-'a')+'a');
        pr += (char)(max(s[i]-'a',t[i]-'a')+'a');
        p[pr]++;
    }

    int ctr = 0;

    for(auto x: p){
        if(x.se%2==1){

            if(x.fi[0]!=x.fi[1]){
                no();
                return;
            }
            ctr++;
            if(ctr>1){
                no();
                return;
            }
        }
    }

    yes();
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

