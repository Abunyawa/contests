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
    int n;
    cin>>n;
    vi a(n+1,0);
    priority_queue<pair<int,pair<int,int>>> q;
    q.push({n,{-1,n}});
    int i = 1;
    while(!q.empty()){
        int l = -q.top().S.F; 
        int r = q.top().S.S; 
        q.pop();
        if((r-l+1)%2==0){
            a[(l+r-1)/2] = i++;
            int mid = (l+r-1)/2;
            if(mid-1-l+1>0){
                q.push({(mid-l),{-l,mid-1}});
            }
            if(r-mid>0){
                q.push({(r-mid),{-(mid+1),r}});
            }
        }else{
            a[(l+r)/2] = i++;
            int mid = (l+r)/2;
            if(mid-1-l+1>0){
                q.push({(mid-l),{-l,mid-1}});
            }
            if(r-mid>0){
                q.push({(r-mid),{-(mid+1),r}});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
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
