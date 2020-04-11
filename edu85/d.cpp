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
    int n;
    ll l,r;
    cin>>n>>l>>r;
    ll curL = 0;
    ll curN = n-1;
    ll sn =1;
    while(curL<l && sn<n){
        curL+=curN*2;
        curN--;
        sn++;
    }
    curL -= l;
    r -= l;
    vl ans(max(r+3,curL+1));
    ll sns = sn-1;
    ll curSec = sn+1;
    for(ll i = curL+1;i<=r;i+=2){
        if(sn==n){
            ans[i] = 1;
            break;
        }
        ans[i] = sn;
        ans[i+1] = curSec++;
        if(curSec>n){
           sn++;
           curSec = sn+1; 
        }
        
    }
    ll crn = n;
    for(ll i = curL;i>=0;i-=2){
        ans[i-1] = sns;
        ans[i] = crn--;
    }
    for(int i=0;i<=r;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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
