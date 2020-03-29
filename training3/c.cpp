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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            b[i][j] = 0;
        }
    }
    vector<pair<int,int> > ans;
    bool flag = true;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j]==1 && a[i+1][j]==1 && a[i+1][j+1]==1 && a[i][j+1]==1){
                if(b[i][j]==0 || b[i+1][j]==0 || b[i+1][j+1]==0 || b[i][j+1]==0){
                    ans.pb(mp(i,j));
                    b[i][j] = 1;
                    b[i+1][j] = 1;
                    b[i][j+1] = 1;
                    b[i+1][j+1] = 1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=b[i][j]){
                flag = false;
            }
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }else{
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].F+1<<' '<<ans[i].S+1<<endl;
        }
    }

    return 0;
}