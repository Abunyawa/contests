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
    vector<int> mnC(n,999999999);
    vector<int> mnR(n,999999999);
    int dck[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dck[i][j];
            if(dck[i][j]<mnC[j]){
                mnC[j] = dck[i][j];
            }
            if(dck[i][j]<mnR[i]){
                mnR[i] = dck[i][j];
            }
        }
    }
    sort(all(mnC));
    sort(all(mnR));
    ll ans1 = 0;
    for(int i = 0;i<n;i++){
        ans1+=min(mnR[i],mnC[i]);
    }
    ll ans2 = 0;
    for(int i = 0;i<n;i++){
        ans2+=min(mnR[i],mnC[n-1-i]);
    }
    ll ans3 = 0;
    for(int i = 0;i<n;i++){
        ans3+=min(mnR[n-1-i],mnC[n-1-i]);
    }
    ll ans4 = 0;
    for(int i = 0;i<n;i++){
        ans4+=min(mnR[n-1-i],mnC[i]);
    }
    cout<<max(max(ans1,ans2),max(ans3,ans4))<<'\n';

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
