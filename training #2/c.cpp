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
    ll l,x,d,m;
    cin>>l>>x>>d>>m;
    if(m==1){
        cout<<-1<<endl;
    }else{
        ll ans = (d+(m-1)*x-1)/((m-1)*x);
        cout<<max(ans+1,2ll)<<endl;
    }
    return 0;
}