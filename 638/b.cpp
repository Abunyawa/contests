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
    int n,k;
    cin>>n>>k;
    vl a(n+1);
    vl ans;
    bool flag = true;
    int mx = 0;
    int mn = n+1;
    set<int> s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }    
    //sort(all(s));
    for(auto j = s.begin();j!=s.end();j++){
        ans.pb(*j);
    }
    sort(all(ans));
    if(ans.size()>k){
        cout<<-1<<'\n';
    }else{
        cout<<n*k<<'\n';
        for(int i=0;i<n;i++){
            for(int j=0;j<k-ans.size();j++){
                cout<<1<<' ';
            }
            for(auto j = 0;j<ans.size();j++){
                cout<<ans[j]<<' ';
            }
        }
        
        cout<<'\n';
    }
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
