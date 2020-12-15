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


const ll MOD = 1e9+7;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int p[20][20];
ll powM(ll a, ll p){
    if(p==0){
        return 1;
    }
    if(p==1){
        return a;
    }
    if(p%2==0){
        ll tmp = powM(a,p/2);
        return (tmp*tmp)%MOD;
    }else{
        return a*powM(a,p-1)%MOD;
    }
}
ll fact(int n){
    ll ret = 1;
    for(int i=2;i<=n;i++){
        ret = (ret*i)%MOD;
    }
    return ret;
}

/*


1 1 1 1 1

*/
void solve() {
    string s;
    getline(cin,s);
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            cout<<"000000 ";
        }else{
            string ans = "";
            if(s[i]>='a' && s[i]<='z'){
                ans+="0";
                int num = s[i]-'a' + 1;
                for(int k = 0;k<5;k++){
                    if(num&(1<<k)){
                        ans+='1';
                    }else{
                        ans+='0';
                    }
                }
            }else{
                ans+="1";
                int num = s[i]-'A' + 1;
                for(int k = 0;k<5;k++){
                    if(num&(1<<k)){
                        ans+='1';
                    }else{
                        ans+='0';
                    }
                }
            }
            cout<<ans<<' ';

        }
    }
    cout<<'\n';
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

