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
    int n = s.length();
    vi ctr(26,0);
    for(int i=0;i<s.length();i++){
        ctr[s[i]-'a']++;
    }

    vi ans(n,-1);
    int cur = 0;
    for(int i=0;i<26;i++){
        if(ctr[i]>0){
            if(ctr[i]%2==0){
                for(int k=0;k<ctr[i]/2;k++){
                    ans[cur] = i;
                    ans[n-1-cur] = i;
                    cur++;
                }
                continue;
            }else{
                for(int k=0;k<ctr[i]/2;k++){
                    ans[cur] = i;
                    ans[n-1-cur] = i;
                    cur++;
                }

                ans[cur] = i;
                int rm = cur;
                for(int let = i+1;let<26;let++){
                    if(ctr[let]!=0){
                        for(int k=0;k<ctr[let];k++){
                            ans[n-1-cur] = let;
                            cur++;
                        }
                    }
                }

                for(int i=rm;i+1<(n+1)/2;i++){
                    if(ans[i+1]==ans[n-1-i]){
                        int tmp = ans[i+1];
                        ans[i+1] = ans[i];
                        ans[i] = tmp;
                    }else{
                        break;
                    }
                }
                break;
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        cout<<(char)('a'+ans[i]);
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

