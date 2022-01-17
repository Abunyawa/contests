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
    string s1, s2;
    cin>>s1>>s2;
    string s3,s4;
    cin>>s3>>s4;
    
    int fr;
    int se;
    if(s1=="AD"){
        fr = stoi(s2);
    }else{
        fr = -(stoi(s1)-1);
    }

    if(s3=="AD"){
        se = stoi(s4);
    }else{
        se = -(stoi(s3)-1);
    }

    cout<<abs(fr-se)<<'\n';

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

