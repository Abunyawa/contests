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
double const PI = 3.14159265359;

vector<int> fn(1000011,0);
int n;

void update(int i,int add)
{
    while(i>0&&i<=n)
    {
        fn[i]=fn[i]+add;
        i=i+(i&(-i));
    }
}
int get(int i)
{
    int s=0;
    while(i>0)
    {
        s=s+fn[i];
        i=i-(i&(-i));
    }
    return s;
}


void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

void solve(){
    int q;
    cin>>n>>q;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        update(x,1);
    }
    
    for(int i=0;i<q;i++){
        int nm;
        cin>>nm;
        if(nm>0){
            update(nm,1);
        }else{
            nm*=-1;
            int l = 1;
            int r = n;
            while(l<r){
                int mid = (r+l)/2;
                if(nm<=get(mid)){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            update(l,-1);
        }
    }

    for(int i=1;i<=n;i++){
        if(get(i)>0){
            cout<<i<<'\n';
            return;
        }
    }
    cout<<0<<'\n';
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
