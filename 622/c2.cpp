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
    vector<ll> m(n);
    ll max = 0;
    ll maxIn = 0;
    for(int i =0;i<n;i++){
        cin>>m[i];
        if(m[i]>max){
            max = m[i];
            maxIn = i;
        }
    }
    
    
    for(int i=0;i<n;i++){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;
    return 0;
}