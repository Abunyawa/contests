#include<bits/stdc++.h>
using namespace std;
bool is[4000100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q,x;
    cin>>q>>x;
    long long mex=0;
    for(int i=0;i<q;i++){
        long long y;
        cin>>y;
        for(int j=mex;;j++){
            if((y-j)%x==0){
                if(is[j]!=true){
                    is[j]=true;
                    break;
                }
            }
            
        }
        for(int j = mex;;j++){
            if(!is[j]){
                mex = j;
                break;
            }
        }
        cout<<mex<<endl;
        

    }

    return 0;
}