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

void solve(){
    int n;
    cin>>n;
    vl a(n);
    vl b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int p = 0;
    int ne = 0;
    for(int i = 0;i<n;i++){
        if(b[i]-a[i]>0){
            if(!p){
                no();
                return;
            }
        }else if(b[i]-a[i]<0){
            if(!ne){
                no();
                return;
            }
        }
        if(a[i]>0){
            p = 1;
        }
        if(a[i]<0){
            ne = 1;
        }
    }
    yes();
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
