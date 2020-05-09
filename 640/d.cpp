#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

void solve(){
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=n;
    ll al = 0;
    ll bob = 0;
    ll all = 0;
    ll bobl = 0;
    int ans = 0;
    while(l<=r){
        ll cur = 0;
        while(cur<=bobl && l<=r){
            cur+=a[l++];
        }
        al += cur;
        all = cur;
        ans++;
        if(l>r){
            break;
        }
        cur = 0;
        while(cur<=all && l<=r){
            cur+=a[r--];
        }
        ans++;
        bobl = cur;
        bob += cur;
    }
    cout<<ans<<' '<<al<<' '<<bob<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
