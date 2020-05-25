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
    int n,m;
    cin>>n>>m;
    vl p;
    for(int i=0;i<n;i++){
        ll num = 0;
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            if(x=='1') num+=(1<<(m-j-1));
        }
        p.pb(num);
    }
    sort(all(p));
    int k = (1<<m)-n;
    int l=0
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
