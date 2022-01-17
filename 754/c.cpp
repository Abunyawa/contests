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

    int prev1 = -1;
    int prev2 = -1;
    int ans = -1;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            if(prev1!=-1 && prev2 != -1){
                int a = 0;
                int b = 0;
                int c = 0;
                for(int j = prev2;j<=i;j++){
                    if(s[j]=='a') a++;
                    else if(s[j]=='b') b++;
                    else c++;
                }
                if(a>c && a>b){
                    if(ans==-1){
                        ans = i-prev2+1;
                    }else{
                        ans = min(i-prev2+1,ans);
                    }
                }
            }


            if(prev1!=-1){
                int a = 0;
                int b = 0;
                int c = 0;
                for(int j = prev1;j<=i;j++){
                    if(s[j]=='a') a++;
                    else if(s[j]=='b') b++;
                    else c++;
                }
                if(a>c && a>b){
                    if(ans==-1){
                        ans = i-prev1+1;
                    }else{
                        ans = min(i-prev1+1,ans);
                    }
                }
            }


            prev2 = prev1;
            prev1 = i;
        }
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

