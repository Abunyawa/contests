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
    ll glAns = 0;
    vector<ll> ans1(n);
    for(int i=0;i<n;i++){
        vector<ll> m1(n);
        for(int j =0;j<n;j++){
            m1[j]=m[j];
        }
        int l = i-1;
        int r = i+1;
        ll ans = m1[i];

        while(l>=0 && r<n){
            m1[l] = min(m1[l],m1[l+1]);
            ans+=m1[l--]; 
            m1[r] = min(m1[r],m1[r-1]);
            ans+=m1[r++];
        }
        while(l>=0){
            m1[l] = min(m1[l],m1[l+1]);
            ans+=m1[l--]; 
        }
        while(r<n){
            m1[r] = min(m1[r],m1[r-1]);
            ans+=m1[r++];
        }
        if(ans>glAns){
            glAns = ans;
            for(int j =0;j<n;j++){
                ans1[j]=m1[j];
            }
        }

    }

    
    for(int i=0;i<n;i++){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;
    return 0;
}