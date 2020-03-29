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
    int n;
    cin>>n;
    vector<ll> x(n);
    int odd = 0;
    int even = 0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        if(x[i]%2==0){
            even++;
        }else{
            odd++;
        }
    }
    ll ans;
    if(odd>even){
        ans=even;
    }else{
        ans=odd;
    }
    cout<<ans<<endl;

    return 0;
}