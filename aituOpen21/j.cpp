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

int eval(string s, int n){
    int ans = 0;
    int cur = 0;
    for(int i=0;i<s.length();i++){
        if((1<<i)&n){
            cur*=10;
            cur+=s[i]-'0';
            //cout<<cur<<' ';
            ans+=cur;
            cur = 0;
        }else{
            cur*=10;
            cur+=s[i]-'0';
        }
    }
    //cout<<cur<<'\n';
    ans+=cur;
    return ans;
}

void solve() {
    /*
    string s;
    cin>>s;
    int n = s.length();
    for(int i=0;i<(1<<(n-1));i++){
        if(eval(s,i)%3==0){
            yes();
            return;
        }
    }
    no();
    */

   ll n;
   cin>>n;
   if(n%3==0){
       yes();
   }else{
       no();
   }
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

