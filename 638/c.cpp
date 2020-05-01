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
    vector<char> s(n);
    for(int i = 0;i<n;i++){
        cin>>s[i];
    }
    sort(all(s));
    if(k==1){
        for(auto e: s){
            cout<<e;
        }
        cout<<'\n';
    }else if(k==n){
        cout<<s[n-1]<<'\n';
    }else{
        int lm = 0;
        while(s[lm]!=s[k-1]){
            lm++;
        }
        if(lm!=0){
            cout<<s[k-1]<<'\n';
            return;
        }
        if(s[n-1]==s[k]){
            cout<<s[k-1];
            for(int i=0;i<(n-k+k-1)/k;i++){
                cout<<s[n-1];
            }
            cout<<'\n';
        }else{
            for(int i=k-1;i<n;i++){
                cout<<s[i];
            }
            cout<<'\n';
        }
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
