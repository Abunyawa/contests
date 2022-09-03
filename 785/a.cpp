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

    if(s.length()==1){
        cout<<"Bob "<<s[0]-'a'+1<<'\n';
        return;
    }

    int sm= 0;
    for(int i=0;i<s.length();i++){
        sm+=s[i]-'a'+1;
    }

    if(s.length()%2==1){
        cout<<"Alice "<<sm-2*min(s[0]-'a'+1, s[s.length()-1]-'a'+1)<<'\n';
    }else{
        cout<<"Alice "<<sm<<'\n';
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

