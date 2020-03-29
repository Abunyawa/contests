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
    int n;
    cin>>n;
    vector<pll> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i].S;
    }
    vector<ll> t(n);
    for(int i=0;i<n;i++){
        cin>>x[i].F;
    }
    sort(all(x));
    ll ans = 0;
    stack<pll> st;
    ll prev = 0;
    for(int i =0;i<n;i++){
        if(st.empty()){
            st.push(x[i]);
        }else{
            while(!st.empty() && st.top().S>x[i].S){
                st.pop();
            }
            if(!st.empty()){
                ans+=abs(st.top().S-x[i].S)+prev;
                prev += abs(st.top().S-x[i].S);
            }
            st.push(x[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}