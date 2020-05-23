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
    ll n,m,k;
    cin>>n>>m>>k;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll a;
        cin>>a;
        a--;
        int num =  a/m;       
        a%=m;
        if(num%2==0){
            if(a<k){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            if(a>=m-k){
                cout<<1;
            }else{
                cout<<0;
            }
        }
    }
    cout<<'\n';
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
