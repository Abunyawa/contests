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
    if(n<=3){
        cout<<-1<<'\n';
        return;
    }
    vi a(n);
    int cur = 1;
    int l=0,r=n-1;
    while(l<=r){
        a[l++] = cur++;
        if(l>r) break;
        a[r--] = cur++;
    }
    int mid = (n-1)/2;

    if(n%2==0){
        int tmp = a[mid];
        a[mid] = a[mid-1];
        a[mid-1] = tmp;
    }else{
        int tmp = a[mid+1];
        a[mid+1] = a[mid+2];
        a[mid+2] = tmp;
    }
    
    for(auto e: a){
        cout<<e<<' ';
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
