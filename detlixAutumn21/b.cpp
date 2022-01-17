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
    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;
    int ctr = 0;
    for(int i=0;i<n-2;i++){
        if(s[i] == 'a' && s[i+1]=='b' && s[i+2]=='c'){
            ctr++;
        }
    }

    for(int i=0;i<q;i++){
        int p;
        char c;
        cin>>p>>c;
        p--;
        
        for(int j=p-2;j<=p && j<n-2;j++){
            if(s[j] == 'a' && s[j+1]=='b' && s[j+2]=='c'){
                ctr--;
            }
        }

        s[p] = c;
        for(int j=p-2;j<=p && j<n-2;j++){
            if(s[j] == 'a' && s[j+1]=='b' && s[j+2]=='c'){
                ctr++;
            }
        }

        cout<<ctr<<'\n';
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

