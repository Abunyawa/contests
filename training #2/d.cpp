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
ll fa[1000100]; 
int main(){
    ll sm = 0;
    for(int i=1;i<=1000000;i++){
        sm+=i;
        fa[i]=sm;
    }
    int t;
    cin>>t;
    while(t--){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        ll n = (y-x)/(a+b);
        for(int i=1;i<=1000000;i++){
            if(fa[i]>n){
                n = i;
                break;
            }
        }
        if(x+fa[n]*a>=y-fa[n-1]*b){
            cout<<y-fa[n-1]*b<<endl;
        }else{
            cout<<x+fa[n]*a<<endl;
        }
    }
    
    return 0;
}