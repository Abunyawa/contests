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
ll pow2[64];

void solve(){
    int n;
    cin>>n;
    if(n%4!=0){
        no();
    }else{
        vector<int> ans(n);
        int cur = 2;
        for(int i=0;i<n/2;i++){
            ans[i] = cur;
            cur+=2;
        }
        int k = 0;
        int ptr = 0;
        for(int i=n/2;i<n;i++){
            if(i!=n-1){
                ans[i] = ans[ptr] - 1;
            }else{
                ans[i] = ans[ptr] + (n/2-1);
            }
            ptr++;
            k++;
        }
        yes();
        for(auto e: ans){
            cout<<e<<' ';
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
