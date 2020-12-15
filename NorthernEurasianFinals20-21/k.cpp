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
vi g[200100];



void solve() {
    int n;
    cin>>n;
    bool flag = false;
    int bestPR = 0;
    int ind = 0;
    for(int i=0;i<n;i++){
        int pr;
        cin>>pr;
        string s;
        cin>>s;
        vi dig(10,0);
        for(int j = 0;j<s.size();j++){
            dig[s[j]-'0']++;
        }
        if(dig[0]>=1 && dig[2]>=2 && dig[1]>=1){
            if(!flag){
                bestPR  = pr;
                ind = i+1;
                flag = true;
            }else{
                if(pr<bestPR){
                    ind = i+1;
                    bestPR = pr;
                }
            }
        }
    }

    cout<<ind<<'\n';
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

