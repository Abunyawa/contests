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
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        ll best = max(max(x,y)-1-(n-max(x,y)),0ll)+1;
        ll worst =  min(x+y-1,n);
        cout<<best<<' '<<worst<<endl;
        
    }

    return 0;
}