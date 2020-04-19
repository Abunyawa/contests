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
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ind = 0;
    for(int i=0;i<n;i++){
        cin>>b[i];
    
    }
    ll cur = 0;
    ll dl = n;
    ll mxAns = 0;
    ll mx = 0;
    for(int i=0;i<n && dl>=0;i++){
        if(b[i]>mx){
            mx=b[i];
        }
        if(cur+mx*dl>mxAns){
            mxAns = cur+mx*dl;
        }
        if(-a[i]<=cur){
            dl--;   
            cur+=a[i];
        }else{
            if(mx!=0){
                int need = (-a[i]-cur+mx-1)/mx;
                if(need<dl){
                    dl--;
                    dl-=need;
                    cur+=need*mx;
                    cur+=a[i];
                }else{
                    break;
                }
            }else{
                break;
            }
        }
        
    }
    cout<<mxAns<<'\n';
    
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
