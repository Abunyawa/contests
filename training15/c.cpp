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

int binp(vl &a,int n,ll x){
    int l = n,r = a.size()-1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(a[mid]>=x){
            r = mid;
        }else{
            l = mid;
        }
    }

    if(a[r]<=x)
        return r;
    if(a[l]<=x)
        return l;
    return l;
}

void solve(){
    int n;
    ll l;
    cin>>n>>l;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    double mx = 0;
    if(n==1){
        mx = max(mx,max((double)a[0],(double)(l-a[0])));
        printf("%.9f\n",mx);
        return;
    }
    for(int i=0;i<n;i++){
        if(i==0){
            mx = max(mx,max((double)(a[i+1]-a[i])/2,(double)a[i]));
        }else if(i==n-1){
            mx = max(mx,max((double)(a[i]-a[i-1])/2,(double)(l-a[i])));
        }else{
            mx = max(mx,max((double)(a[i]-a[i-1])/2,(double)(a[i+1]-a[i])/2));
        }
    }
    printf("%.9f\n",mx);
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
