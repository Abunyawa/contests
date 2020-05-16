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
    int n,k;
    cin>>n>>k;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<k){
        cout<<a[n-1]<<'\n';
        return;
    }
    vl mx(k);
    int ptr = n-1;
    for(int i=0;i<k;i++){
        mx[i] = a[ptr--]; 
    }
    int left = n-k;
    ptr = left-1;
    for(int i=k-1;i>=0 && ptr>=0;i--){
        mx[i] += a[ptr--];
    }
    sort(all(mx));
    cout<<mx[k-1]<<'\n';
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
