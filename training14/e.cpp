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
    int n,m;
    cin>>n>>m;
    vi a(n);
    ll mn = 101;
    ll mx = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>mx){
            mx = a[i];
        }
        if(a[i]<mn){
            mn = a[i];
        }
    }
    vi b(m);
    ll mnb = 101;
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(b[i]<mnb){
            mnb=b[i];
        }
    }
    ll need = max(mn*2,mx);
    if(need>=mnb){
        cout<<-1<<'\n';
    }else{
        cout<<need<<'\n';
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
