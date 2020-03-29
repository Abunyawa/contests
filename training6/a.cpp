#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
using namespace std;


void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
double smAll(vector<int> &a,int l, int r){
    double sm = 0;
    for(int i=l;i<=r;i++){
        sm+=a[i];
    }
    return sm;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = 0;
    int l=0,r=0;
    while(r<n){
        while(a[r]>0 && r<n){
            r++;
        }
        if(r-l>ans && a[l]>0 && a[r-1]>0){
            ans=r-l;
        }
        l = r;
        while(a[l]<=0 && l<n){
            l++;
        }
        r=l;
    }
    cout<<ans<<endl;
    return 0;
}