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

    vector<string> s(2*n);
    vi alph(26,0);
    for(int i=0;i<2*n;i++){
        cin>>s[i];
        
        for(int j=0;j<s[i].length();j++){
            alph[s[i][j]-'a']++;
        }
    }

    string x;
    cin>>x;

    for(int j=0;j<x.length();j++){
        alph[x[j]-'a']++;
    }

    for(int i=0;i<26;i++){
        if(alph[i]%2==1){
            cout<<(char)(i+'a')<<'\n';
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

/*

a
ab
ab

*/