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
    cout<<"Yes"<<endl;
}

void no(){
    cout<<"No"<<endl;
}

ll dp[2010];
void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(x>=i&&x<=j&&y>=i&&y<=j){
                dp[j-i-abs(x-y)+1]++;
            }else{
                if(x>=i&&x<=j){
                    if(y-j+1<j-x){
                        dp[x-i+1+y-j]++;
                    }else{
                        dp[j-i]++;
                    }
                }else if(y>=i&&y<=j){
                    if(i-x+1+j-y<j-i){
                        dp[i-x+1+j-y]++;
                    }else{
                        dp[j-i]++;
                    }
                }else if(i>x && j<y){
                    if(i-x+1+y-j<j-i){
                        dp[i-x+1+y-j]++;
                    }else{
                        dp[j-i]++;
                    }
                }else{
                    dp[j-i]++;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<dp[i]<<endl;
    }
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
