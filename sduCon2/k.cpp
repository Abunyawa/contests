#include<bits/stdc++.h>
using namespace std;
int d[10000000];
bool flag = false;
void check(int* mov, int cur,int n){
    if(cur>=n){
        int sm=0;
        for(int i=0;i<n;i++){
            sm+= mov[i]*d[i];
        }
        if(sm%360==0){
            flag = true;
        }
    }else{
        for(int i = -1;i<=1;i+=2){
            d[cur] = i;
            check(mov,cur+1,n);
        }
    }

}
int main(){
    int n;
    cin>>n;
    int mov[n];
    for(int i =0;i<n;i++){
        cin>>mov[i];
    }

    check(mov,0,n);

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}