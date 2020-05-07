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
ll num[200100];

void solve(){
    ll n;
    cin>>n;
    int i = 1;
    while(num[i]<=n){
        i++;
    }
    int ans = 0;
    for(int j=i;j>=1;j--){
        if(n>=num[j]){
            ans+=n/num[j];
            n%=num[j];
        }
    }
    cout<<ans<<"\n";
}

int main(){


    abu;
    said;
    ll all = 0;
    for(int i=1;i<=200000;i++){
        all+=i*2+i-1;
        num[i] = all;
    }
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
