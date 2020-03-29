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

int main(){
    //freopen("collect.in","r",stdin);
    //freopen("collect.out","w",stdout);
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<ll> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(all(a));
    for(int i=0;i<m;i++){
        int l=0,r=n-1;
        int piv = l+(r-l)/2;

        while(l<r){
            piv = l+(r-l)/2;
            if(b[i]==a[piv]){
                yes();
                break;
            }
            if(b[i]<a[piv]){
                r = piv-1;
            }
            if(b[i]>a[piv]){
                l=piv+1;
            }
        }
        if(a[l]!=b[i] && a[r]!=b[i] && a[piv] != b[i]){
            no();
        }else{
            yes();
        }
    }
    return 0;
}