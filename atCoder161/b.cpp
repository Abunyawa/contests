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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}

void solve(){
    int n;
    double m;
    cin>>n>>m;
    vector<double> a(n);
    double sm =0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }
    sort(all(a));
    int ctr = 0;
    for(int i=n-1;ctr<m && i>=0;i--){
        if(a[i]/sm>=1/(4*m)){
            ctr++;
        }
    }
    if(ctr==m){
        yes();
    }else{
        no();
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
