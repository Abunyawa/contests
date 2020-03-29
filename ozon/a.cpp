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
    vi b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
}

int main(){
    abu;
    said;
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}