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
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    ll mx;
    ll mn;
    int ch = 0;
    if(n==2){
        ll a1 = a[0];
        ll b = a[0];
        ll c = a[n-1];
        if(c<a1){
            cout<<a1-c<<'\n';
        }else if(c>=a1 && c<=b){
            cout<<0<<'\n';
        }else{
            cout<<c-b<<'\n';
        }
        return;
    }

    if(n%2==1){
        mx = min(a[0],a[1]);
        mn = max(a[0],a[1]);
    }else{
        mn = min(a[0],a[1]);
        mx = max(a[0],a[1]);
        ch =1;
    }
    for(int i=2;i<n-1;i++){
        if(ch%2==0){
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
            ch++;
        }else{
            mn = max(mn,a[i]);
            mx = min(mx,a[i]);
            ch++;
        }
    }

    ll a1 = mx;
    ll b = mn;
    ll c = a[n-1];
    if(c<a1){
        cout<<a1-c<<'\n';
    }else if(c>=a1 && c<=b){
        cout<<0<<'\n';
    }else{
        cout<<c-b<<'\n';
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

