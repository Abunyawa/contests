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
    vl v(n+1);
    vl pS(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pS[i] = pS[i-1]+v[i];
    }
    sort(all(v));
    vl pS2(n+1,0);
    for(int i=1;i<=n;i++){
        pS2[i] = pS2[i-1]+v[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            cin>>l>>r;
            cout<<pS[r]-pS[l-1]<<'\n';
        }else{
            int l,r;
            cin>>l>>r;
            cout<<pS2[r]-pS2[l-1]<<'\n';
        }
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
