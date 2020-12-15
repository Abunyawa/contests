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
    string s;
    cin>>s;
    int s1=0;
    int s2=0;
    int s3=0;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            if(s1>0){
                s1--;
                ans++;
            }
        }else if(s[i]=='}'){
            if(s2>0){
                s2--;
                ans++;
            }
        }else if(s[i]==']'){
            if(s3>0){
                s3--;
                ans++;
            }
        }else{
            if(s[i]=='(') s1++;
            if(s[i]=='{') s2++;
            if(s[i]=='[') s3++;
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

