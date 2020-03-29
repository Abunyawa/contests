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
int main(){
    int gg;
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    vector<ll> pref(n+1);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            cout<<i<<' '<<i<<endl;
            return 0;
        }
        pref[i] = pref[i-1]+a[i];
    }
    int l=1,r=1;
    bool flag = false;
    int ansS = 1, ansF = n;
    while(l<=r && r<=n){
        while(pref[r]-pref[l-1]<k && r<=n){
            r++;
        }
        if(pref[r]-pref[l-1]==k){
            flag = true;
            if(r-l+1<ansF-ansS+1){
                ansS = l;
                ansF = r;
            }
        }
        while(pref[r]-pref[l-1]>k && l<=r){
            l++;
        }
        if(pref[r]-pref[l-1]==k){
            flag = true;
            if(r-l+1<ansF-ansS+1){
                ansS = l;
                ansF = r;
            }
            l++;
        }
    }
    if(flag)
        cout<<ansS<<' '<<ansF<<endl;
    else
        cout<<-1<<endl;
    
    return 0;
}