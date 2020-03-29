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
    int n,k;
    cin>>n>>k;
    vector<ll> t(k);
    vector<ll> q(k,0);
    for(int i=0;i<k;i++){
        cin>>t[i];
    }
    vector<pair<ll,pair<ll,int>> > que;

    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        que.pb(mp(a,mp(i,b)));
    }
    sort(all(que));
    vector<ll> ans(n);
    for(int i=0;i<n;i++){
        ll a=que[i].F,b=que[i].S.S;
        for(int i=0;i<k;i++){
            if(q[i]>=a){
                q[i]-=a;
                break;
            }else{
                a-=q[i];
                q[i] = 0;
            }
        }
        ll totT  = 0;
        for(int i=0;i<k;i++){
            if(q[i]+t[i]>=b){
                q[i]+= t[i]-b;
                totT=-1;
                break;
            }else{
                b-=q[i]+t[i];
                q[i] +=t[i];
                totT += q[i];
            }
        }
        ans[que[i].S.F]=totT;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}