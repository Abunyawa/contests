#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int ctr[110];
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        ctr[a[i]%k]++;
    }
    int ans = ctr[0]/2*2;
    for(int i=1;i<k;i++){
        if(i==k-i){
            ans+=ctr[i]/2*2;
            continue;
        }
        ans+=min(ctr[i],ctr[k-i]);
    }
    cout<<ans<<endl;
    return 0;
}