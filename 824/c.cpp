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


    vi g(26,-1);
    vi used(26,false);
    string ans="";

    for(int i=0;i<n;i++){
        if(g[s[i]-'a']==-1){

            for(int k = 0;k<26;k++){
                if(k==(s[i]-'a') || used[k]){
                    continue;
                }

                if(g[k]==-1){
                    used[k]=1;
                    g[s[i]-'a']=k;
                    break;
                }else{
                    int ctr = 0;
                    int str = k;

                    while(g[str]!=-1){
                        ctr++;
                        str = g[str];
                    }

                    if(str==(s[i]-'a')){
                        if(ctr!=25){
                            continue;
                        }else{
                            used[k]=1;
                            g[s[i]-'a']=k;
                            break;
                        }
                    }else{
                        used[k]=1;
                        g[s[i]-'a']=k;
                        break;
                    }
                }
            }
        }

        ans+=(char)('a'+g[s[i]-'a']);
    }

    cout<<ans<<'\n';
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

