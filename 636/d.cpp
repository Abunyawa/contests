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
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    /*
    map<int,int> ct;
    int cta = 0;
    int freqS = 0;
    for(int i=0;i<n/2;i++){
        ct[a[i]+a[n-i-1]]++;
        if(ct[a[i]+a[n-i-1]]>cta){
            cta = ct[a[i]+a[n-i-1]];
            freqS = a[i]+a[n-i-1];
        }else if(ct[a[i]+a[n-i-1]]=cta){
            if(freqS<a[i]+a[n-i-1])
                freqS = a[i]+a[n-i-1];
        }
    }
    int ctr = 0;
    for(int i=0;i<n/2;i++){
        if(a[i]+a[n-i-1]!=freqS){
            if(freqS - a[i]<=k &&freqS - a[i]>0){
                ctr++;
            }else if(freqS - a[n-i-1]<=k && freqS - a[n-i-1]>0){
                ctr++;
            }else{
                ctr+=2;
            }
        }
    }
    */
    int mx = 0;
    for(int i=0;i<n/2;i++){
        if(a[i]+a[n-i-1]>mx){
            mx=a[i];
        }
    }
    int ctr2 = 0;
    for(int i=0;i<n/2;i++){
        if(a[i]+a[n-i-1]!=min(mx,k+1)){
            ctr2++;
        }
    }
    cout<<ctr2<<'\n';
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
