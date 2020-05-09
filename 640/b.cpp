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
    ll n,k;
    cin>>n>>k;
    if(n<k){
        no();
        return;
    }
    if(n%k==0){
        yes();
        for(int i=0;i<k;i++){
            cout<<n/k<<' ';
        }
        cout<<'\n';
    }else{
        if((n-(k-1))%2==1){
            yes();
            for(int i=0;i<k-1;i++){
                cout<<1<<' ';
            }
            cout<<(n-(k-1))<<' ';
            cout<<'\n';
        }else if((n-(k-1)*2)%2==0 && n-(k-1)*2>0){
            yes();
            for(int i=0;i<k-1;i++){
                cout<<2<<' ';
            }
            cout<<(n-(k-1)*2)<<' ';
            cout<<'\n';
        }else{
            no();
        }
    }
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
