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
vector<int> g[200100];
int ctr = 0;
bool used[200100];

void solve(){
    int n = 4;
    vl a(n);
    ll sm = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }
    if(sm%2!=0){
        no();
        return;
    }
    for(int i = 1;i<4;i++){
        if(a[i]+a[0]==sm/2){
            yes();
            return;
        }
    }
    no();
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
