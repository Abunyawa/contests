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
    vi ctrC(10,0);

    for(int i=0;i<s.length();i++){
        ctrC[s[i]-'0']++;
    }
    vi ctr(10,0);
    vector<bool> used(s.length(),false);

    for(int lf = 0;lf<10;lf++){
        int cur = 0;
        for(int i=0;i<s.length();i++){
            if(used[i] || cur==ctrC[lf]) continue;
            if(s[i]-'0'>lf && cur<ctrC[lf]){

                if(s[i]=='9'){
                    ctr[9]++;
                    ctrC[9]--;
                }else{
                    ctr[s[i]-'0'+1]++;
                    ctrC[s[i]-'0']--;
                }

                used[i] = true;
            }else if(s[i]-'0'==lf){
                cur++;
                used[i] = true;
                ctr[lf]++;
            }
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<ctr[i];j++){
            cout<<i;
        }
    }

    cout<<'\n';
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

