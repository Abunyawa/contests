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
    if(n==1){
        cout<<-1<<endl;
        return;
    }
    vi a(n);
    ll sm = 0;
    for(int i=0;i<n-1;i++){
        a[i]=2;
        sm+=2;
    }
    a[n-1] = 3;
    sm+=3;
    if(sm%3==0){
        a[n-2] = 3;
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
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