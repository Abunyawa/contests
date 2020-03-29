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
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            cout<<1<<endl;
            cout<<i+1<<endl;
            return;
        }
    }
    vi ans;
    for(int i=0;i<n;i++){
        if(a[i]%2==1){
            ans.pb(i+1);
        }
    }
    if(ans.size()<2){
        cout<<-1<<endl;
        return;
    }else{
        cout<<2<<endl;
        cout<<ans[0]<<' '<<ans[1]<<endl;
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