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
ll ds[2000101];


void solve(){
    int n,s;
    cin>>n>>s;
    if(s<2*n){
        no();
    }else{
        yes();
        for(int i = 0;i<n-1;i++){
            cout<<2<<' ';
        }
        cout<<s-2*(n-1)<<'\n';
        cout<<1<<'\n';
    }
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
