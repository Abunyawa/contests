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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n>m){
        cout<<0<<endl;
    }else{
        ll ans = 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans*=abs(a[i]-a[j])%m;
                ans%=m;
            }
        }
        cout<<ans%m<<endl;
    }
}

int main(){
    abu;
    said;
    solve();
    

    return 0;
}