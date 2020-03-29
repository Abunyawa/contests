#include<bits/stdc++.h>
using namespace std;
int x[] = {0, 0, 1, 1, 1, -1, -1, -1};
int y[] = {1, -1, 0, 1, -1, 1, -1, 0};

int main(){
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                a[i][j] = '0';
            }
        }

    }
    bool flag = true;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!='*'){
                //               
                int num = (int)(a[i][j]-'0');
                int ctr = 0;
                for(int k=0;k<8;k++){
                    int xto = i+x[k];
                    int yto = j+y[k];
                    if(xto>=0 && xto<n && yto>=0 && yto<m){

                        if(a[xto][yto] == '*') ctr++;
                    }
                }
                if(ctr != num){
                    flag = false;
                }
            }
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}