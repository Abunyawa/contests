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
/*
9 * 9 + 9 * 9 * 9
9*9*(1+81)
*/
bool p[200];
void solve(){
    int n,k;
    cin>>n>>k;
    vl a(n);
    bool flag = true;
    ll mx =0;
    ll sm = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
        if(a[i]>mx){
            mx = a[i];
        }        
    }
    ll ctr = 0;
    for(ll i=1;i<mx;i*=k){
        ctr++;
    }
    vector<vector<int>> ka;
    for(int i=0;i<n;i++){
        ll ck = pow(k,ctr);
        vector<int> la(ctr+1,0);
        for(int j=ctr;j>=0;j--){
            la[j] = a[i]/ck;
            a[i]%=ck;
            ck/=k;
        }
        ka.pb(la);
    }
    for(int i=0;i<=ctr;i++){
        int was = 0;
        for(int j=0;j<n;j++){
            was+=ka[j][i];
        }
        if(was>1){
            flag = false;
        }
    }
    if(flag){
        yes();
    }else{
        no();
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