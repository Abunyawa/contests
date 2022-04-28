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

    int r=0;
    int b=0;

    for(int i=0;i<n;i++){
        if(s[i]=='R') r++;
        else if(s[i]=='B') b++;
        else{
            if((r==0 && b!=0)|| (r!=0 && b==0)){
                no();
                return;
            }
            r = 0;
            b = 0;
        }
    }
    if((r==0 && b!=0)|| (r!=0 && b==0)){
        no();
    }else{
        yes();
    }
    
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

