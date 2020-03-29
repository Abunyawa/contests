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
bool used[100100];
void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int suf[n+1];
    suf[n]=0;
    for(int i=n-1;i>=0;i--){
        if(!used[a[i]]){
            suf[i] = suf[i+1]+1;
            used[a[i]] = true;
        }else{
            suf[i] = suf[i+1];
        }
    }
    for(int i=0;i<m;i++){
        int l;
        cin>>l;
        cout<<suf[l-1]<<endl;
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