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
    bool R=false;
    bool G=false;
    bool B=false;
    for(int i=0;i<6;i++){
        if(s[i]=='r'){
            R = true;
        }else if (s[i]=='g'){
            G = true;
        }else if(s[i]=='b'){
            B = true;
        }else if(s[i]=='R'){
            if(!R){
                no();
                return;
            }
        }else if(s[i]=='G'){
            if(!G){
                no();
                return;
            }
        }else{
            if(!B){
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

