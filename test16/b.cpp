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
    ll a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    bool flag = false;
    if(a1==a2){
        if(b1+b2==a1){
            flag = true;
        }
    }
    if(a1==b2){
        if(a2+b1==a1){
            flag = true;
        }
    }
    if(b2==b1){
        if(a1+a2==b2){
            flag = true;
        }
    }
    if(b1==a2){
        if(a1+b2==b1){
            flag = true;
        }
    }
    if(flag){
        yes();
    }else{
        no();
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
