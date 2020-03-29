#include<bits/stdc++.h>
using namespace std;
int sum[25];


int main(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int a[n][m];
    int max = 0;
    int ind = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            sum[i]+=a[i][j];
        }
        if(sum[i]>max){
            max = sum[i];
            ind = i;
        }else if(sum[i]==max && i==k-1){
            max = sum[i];
            ind = i;
        }
    }
    if(ind==k-1){
        cout<<"YES 0"<<endl;
        return 0;
    }else{
        
        for(int j=0;j<m;j++){
            int mx = 0;
            int ind = -1;
            for(int i=0;i<n;i++){
                if(sum[i]-a[i][j]>mx){
                    mx = sum[i]-a[i][j];
                    ind = i;
                }else if(sum[i]-a[i][j] == mx && i == k-1){
                    mx = sum[i]-a[i][j];
                    ind = i;
                }
            }
            if(ind==k-1){
                cout<<"DEL "<<j+1<<endl;
                return 0;
            }
        }

        for(int j=0;j<m;j++){
            int mx = 0;
            int ind = -1;
            for(int i=0;i<n;i++){
                if(sum[i]-2*a[i][j]+10>mx){
                    mx = sum[i]-2*a[i][j]+10;
                    ind = i;
                }else if(sum[i]-2*a[i][j]+10 == mx && i==k-1){
                    mx = sum[i]-2*a[i][j]+10;
                    ind = i;
                }
            }

            if(ind==k-1){
                cout<<"REV "<<j+1<<endl;
                return 0;
            }
        }
    }
    cout<<"NOP 0"<<endl;


    return 0;
}