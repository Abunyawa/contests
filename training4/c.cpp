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
int ctr[5001];

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    ll x,f;
    cin>>x>>f;
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(a[i]>x){
            ans+=a[i]/(x+f);
            if(a[i]%(x+f)>x){
                ans++;
            } 
        }
    }
    cout<<ans*f<<endl;

    return 0;
}