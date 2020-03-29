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
    int n,k;
    cin>>n>>k;
    int has[n+1];
    has[0] = 0;
    has[1] = 0;
    for(int i=2;i<=n+1;i++){
        has[i] = has[i-1] + (i-1);
    }
    int need = 0;
    for(int i=2;i<=n;i++){
        if(has[i]>=k){
            need = i;
            break;
        }
    }
    vector<char> ans(n,'a');
    if(has[need]==k){
        ans[n-need] = 'b';
        ans[n-need+1] = 'b';
    }else{
        ans[n-need] = 'b';
        ans[n- (k-has[need-1])] = 'b';
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
        //cout<<has[i]<<endl;
    }
    cout<<endl;
    
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
