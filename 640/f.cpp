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

void solve(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    
    if(n1==0 && n2==0){
        for(int i=0;i<=n3;i++){
            cout<<'1';
        }
        cout<<'\n';
    }else if(n2==0 && n3==0){
        for(int i=0;i<=n1;i++){
            cout<<'0';
        }
        cout<<'\n';
    }else{
        for(int i=0;i<=n1;i++){
            cout<<'0';
        }
        for(int i=0;i<=n3;i++){
            cout<<'1';
        }
        for(int i=0;i<(n2-1)/2;i++){
            cout<<"01";
        }
        if((n2-1)%2==1){
            cout<<'0';
        }
        cout<<'\n';
    }
   
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
