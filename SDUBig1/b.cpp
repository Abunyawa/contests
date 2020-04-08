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
    ll t;
    cin>>t;
    vl x(n);
    ll l=0,r=-1;    
    for(int i=0;i<n;i++){
        cin>>x[i];
        if( x[i] >= 0ll && r == -1){
            r = i;
        }
        
    }
    int be = 0;
    
    if(r==-1){
        int c = n-1;
        while(abs(x[c])<=t && c>=0){
            c--;
        }
        if(be<n-1-c)
            be = n-1-c;
        
    }else{
        int c = r-1;
        while(abs(x[c])<=t && c>=0){
            c--;
        }
        if(be<r-c)
            be = r-c-1;
        while(r<n){
            while(r<n && min(abs(x[l]),x[r])+(x[r]-x[l])<=t){
                r++;
            }
            if(r-l>be && min(abs(x[l]),abs(x[r-1]))+(x[r-1]-x[l])<=t){
                be = r-l;
            }
            if(x[l]>=0){
                break;
            }
            if(r<n){
                while(x[l]<0 && min(abs(x[l]),x[r])+(x[r]-x[l])>t){
                    l++;
                }
            }else{
                break;
            }
        }
    }
    cout<<be<<'\n';
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
