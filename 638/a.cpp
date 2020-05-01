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
    
    vl a(n+1);
    for(int i=1;i<=n;i++){
        a[i] = (1<<i);
    }
    ll sm1 = 0;
    ll sm2 = 0;
    for(int i=1;i<n/2;i++){
        sm1+=a[i];    
    }
    for(int i=n/2;i<n;i++){
        sm2+=a[i];    
    }
    sm1+=a[n];
    cout<<abs(sm1-sm2)<<'\n';
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
