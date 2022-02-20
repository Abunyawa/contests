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

const ll MOD = 1e9+7;
ll calc[200100];
ll pref[200100];

bool check(string s){
    int sz = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            sz++;
        }else{
            if(sz%2==1){
                return false;
            }else{
                sz = 0;
            }
        }
    }
    if(sz%2==1){
        return false;
    }else{
        return true;
    }
    
}

void solve() {
    int n, p;
    cin>>n>>p;

    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    vl good;
    set<string> st;

    for(int i=0;i<n;i++){
        ll num = a[i];

        string bin;

        while(num!=0){
            bin += num%2==1?"1":"0";
            num/=2;
        }
        bool flag = true;
        reverse(all(bin));
        for(int i=0;i<bin.length();i++){
            if(st.find(bin.substr(0,i+1))!=st.end()){
                if(check(bin.substr(i+1))){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            st.insert(bin);
            good.pb(a[i]);
        }
    }

    ll ans = 0;
    

    for(int i=0;i<good.size();i++){
        int len = 0;
        while(good[i]>0){
            len++;
            good[i]/=2;
        }
        //cout<<len<<' ';
        int left = p - len;
        if(left>=0){
            ans = (ans+1)%MOD;
            if(left>0){
                ans = (ans + pref[left])%MOD;
            }
        }
    }

    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    calc[1] = 1;
    calc[2] = 2;
    for(int i=3;i<200100;i++){
        calc[i] = (calc[i-1] + calc[i-2])%MOD;
    }
    for(int i=1;i<200100;i++){
        pref[i] = (pref[i-1] + calc[i])%MOD;
    }
    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

