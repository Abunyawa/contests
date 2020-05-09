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
    vi a(n+1);
    vl pref(n+1);
    pref[0] = 0;
    vl m(n+1,0); 
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[a[i]]+=1;
        pref[i] = pref[i-1]+a[i];
    }
    int ans = 0;
    vl used(n+1,0);
    for(int i=1;i<=n-1;i++){
        for(int j = i+1;j<=n;j++){
            if(pref[j]-pref[i-1]>n) break;
            if(used[pref[j]-pref[i-1]]==0){
                ans+=m[pref[j]-pref[i-1]];
                used[pref[j]-pref[i-1]]=1;
            }
        }
    }
    cout<<ans<<'\n';
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
