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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

void solve(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    char minL = 'z'; 
    vector<pair<string,int> > ans;
    for(int i=0;i<n;i++){
        if(minL>a[i]){
            minL=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==minL){
            string tt="";
            for(int j=i;j<n;j++){
                tt+=a[j];
            }
            if((n-i)%2==0){
                for(int j=0;j<i;j++){
                    tt+=a[j];
                }
            }else{
                for(int j=i-1;j>=0;j--){
                    tt+=a[j];
                }
            }
            ans.pb(mp(tt,i));
        }
    }
    sort(all(ans));
    cout<<ans[0].F<<endl;
    cout<<ans[0].S+1<<endl;

}

int main(){
    abu;
    said;
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}