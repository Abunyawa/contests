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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        bool flag = false;
        for(int j = n-1;j>r;j--){
            if(s[r]==s[j]){
                flag = true;
            }
        }
        for(int j = 0;j<l;j++){
            if(s[l]==s[j]){
                flag = true;
            }
        }

        if(flag){
            yes();
        }else{
            no();
        }
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

