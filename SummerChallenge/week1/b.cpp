#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

ll findNum(vl &a, ll dis){
    ll prev = a[0];
    int num = 1;
    for(int i=1;i<a.size();i++){
        if(a[i]-prev>=dis){
            prev = a[i];
            num++;
        }
    }
    return num;
}


void solve(){
    int n,k;
    cin>>n>>k;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(all(a));
    ll l = 0;
    ll r = a[n-1]-a[0];
    while(l<r-1){
        ll mid = (l+r)/2;
        if(findNum(a,mid)>=k){
            l = mid;
        }else{
            r = mid;
        }
    }
    if(findNum(a,r)>=k)
        cout<<r<<'\n';
    else 
        cout<<l<<'\n';
}

int main(){
    
    freopen("cows.in","r",stdin);
    freopen("cows.out","w",stdout);
    
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
