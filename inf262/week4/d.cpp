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
    int k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(s.length()==1){
        if(k>0){
            cout<<0<<'\n';
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(k==0){
            break;
        }
        if(i==0){
            if(s[i]-'0'>1){
                k--;
                s[i] = '1';
            }
        }else{
            if(s[i]-'0'>0){
                k--;
                s[i] = '0';
            }
        }
    }

    cout<<s<<'\n';
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

