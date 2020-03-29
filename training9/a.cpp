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
    string s;
    cin>>s;
    int n = s.length();
    int pref[n+1];
    pref[0] = 0;
    for(int i=1;i<n;i++){
        if(s[i-1]==s[i]){
            pref[i] = pref[i-1] + 1;
        }else{
            pref[i] = pref[i-1];
        }
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        cout<<pref[r-1]-pref[l-1]<<endl;
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