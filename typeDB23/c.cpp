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
    ll s;
    cin>>n>>s;

    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vl x(n);
    vl y(n);
    for(int i=1;i<n-1;i++){
        if(a[i]<=s){
            x[i] = 0;
            y[i] = a[i];
        }else{
            x[i] = min(a[i]-s,s);
            y[i] = max(a[i]-s,s);

        }
    }

    ll cur = a[0];
    ll ans = 0;

    for(int i=1;i<n-2;i++){
        if(cur>y[i+1]){
            ans+=cur*x[i];
            cur = y[i];
        }else if(cur<x[i+1]){
            ans+=cur*y[i];
            cur = x[i];
        }else{
            ll ls = (x[i]+y[i])/2;
            ll mr = (x[i]+y[i]) - ls;
            
            if(cur*1.0 < (x[i+1]+y[i+1])*1.0/2.0){
                ans+=cur*y[i];
                cur = x[i];
            }else if(cur*1.0 > (x[i+1]+y[i+1])*1.0/2.0){
                ans+=cur*x[i];
                cur = y[i];
            }else{
                ans += cur*ls;
                cur = mr;
            }
        }

        //cout<<(x[i]+y[i]-cur)<<' '<<cur<<'\n';
    }

    if(cur>a[n-1]){
        ans+=cur*x[n-2];
        cur =  y[n-2];
    }else if(cur<a[n-1]){
        ans+=cur*y[n-2];
        cur = x[n-2];
    }else{
        ans+= cur*((x[n-2]+y[n-2]) - ((x[n-2]+y[n-2])/2));

        cur = (x[n-2]+y[n-2])/2;
    }
    //cout<<(x[n-2]+y[n-2]-cur)<<' '<<cur<<'\n';
    ans+=cur*a[n-1];


    reverse(all(a));

    for(int i=1;i<n-1;i++){
        if(a[i]<=s){
            x[i] = 0;
            y[i] = a[i];
        }else{
            x[i] = min(a[i]-s,s);
            y[i] = max(a[i]-s,s);

        }
    }

    cur = a[0];
    ll ans1 = 0;

    for(int i=1;i<n-2;i++){
        if(cur>y[i+1]){
            ans1+=cur*x[i];
            cur = y[i];
        }else if(cur<x[i+1]){
            ans1+=cur*y[i];
            cur = x[i];
        }else{
            ll ls = (x[i]+y[i])/2;
            ll mr = (x[i]+y[i]) - ls;
            
            if(cur*1.0 < (x[i+1]+y[i+1])*1.0/2.0){
                ans1+=cur*y[i];
                cur = x[i];
            }else if(cur*1.0 > (x[i+1]+y[i+1])*1.0/2.0){
                ans1+=cur*x[i];
                cur = y[i];
            }else{
                ans1 += cur*ls;
                cur = mr;
            }
        }

        //cout<<(x[i]+y[i]-cur)<<' '<<cur<<'\n';
    }

    if(cur>a[n-1]){
        ans1+=cur*x[n-2];
        cur =  y[n-2];
    }else if(cur<a[n-1]){
        ans1+=cur*y[n-2];
        cur = x[n-2];
    }else{
        ans1+= cur*((x[n-2]+y[n-2]) - ((x[n-2]+y[n-2])/2));

        cur = (x[n-2]+y[n-2])/2;
    }
    //cout<<(x[n-2]+y[n-2]-cur)<<' '<<cur<<'\n';
    ans1+=cur*a[n-1];


    cout<<min(ans,ans1)<<'\n';
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

