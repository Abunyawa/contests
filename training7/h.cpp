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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int main(){
    abu;
    said;
    ll n;
    cin>>n;
    vector<pll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].F>>a[i].S;
    }
    sort(all(a));
    ll pl = 0;
    for(int i=0;i<n;i++){
        if(a[i].S<pl){
            cout<<"Happy Alex"<<endl;
            return 0;
        }else{
            pl = a[i].S;
        }
    }
    cout<<"Poor Alex"<<endl;
    return 0;
}