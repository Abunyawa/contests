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
/*
2 1 54 53
*/
void solve(){
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll cur = a[0];
    ll x = 1;
    ll d = 0;
    for(int i=1;i<n;i++){
        if(a[i]<cur){
            if(cur-a[i]>d){
                d = cur-a[i];
            }
        }
        else if(a[i]>cur){
            cur = a[i];
        }
    }
    x = 0;
    while(d!=0){
        d/=2;
        x++;
    }
    cout<<x<<'\n';
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