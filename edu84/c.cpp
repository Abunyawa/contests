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

/*
(n-1)+(m-1)+
n*m - 1 

*/
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int minx1 = n+2;
    int miny1 = m+2;
    int maxx1 = 0;
    int maxy1 = 0;
    for(int i=0;i<2*k;i++){
        int x,y;

        cin>>x>>y;
        if(x>maxx1){
            maxx1 = x;
        }
        if(x<minx1){
            minx1 = x;
        }
        if(y>maxy1){
            maxy1 = y;
        }
        if(y<miny1){
            miny1 = y;
        }
    }
    if((n-1)+(m-1)+(n*m-1)>2*n*m){
        cout<<-1<<endl;
    }else{
        cout<<(n-1)+(m-1)+(n*m-1)<<endl;
        for(int i=1;i<m;i++){
            cout<<'L';
        }
        for(int i=1;i<n;i++){
            cout<<'D';
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<n;j++){
                if(i%2==1){
                    cout<<'U';
                }else{
                    cout<<'D';
                }
            }
            if(i!=m){
                cout<<'R';
            }
        }
        cout<<endl;
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
