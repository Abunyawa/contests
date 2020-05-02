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
    int n,d;
    cin>>n>>d;
    vl a(n);
    map<ll,int> m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;

    }
    sort(all(a));
    int ans = 2;
    if(d==2){
        for(int i=0;i<n;i++){
            if(m[a[i]]>=2){
                cout<<0<<'\n';
                return;
            }
        }
        cout<<1<<'\n';
    }else{
        int ans = 2;
        for(int i=0;i<n;i++){
            if(m[a[i]]>=3){
                cout<<0<<'\n';
                return;
            }
            if(m[a[i]]==2 && a[i]!=a[n-1]){
                ans = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(m[a[i]*2]>0){
                ans = 1;
            }
        }

        cout<<ans<<'\n';
    }
}

int main(){
    abu;
    said;
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int t = 1;
    cin>>t;
    for(int i = 1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
