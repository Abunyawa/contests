#include<bits/stdc++.h>
using namespace std;
int d[1000000];
int bits(int *task,int n, int cur, int l, int r, int x){
    if(cur>n){
        //cout<<'1'<<endl;
        int sum =0;
        int hrd = 0;
        int ctr=0;
        int eas = 999999999;
        for(int i =0;i<n;i++){
            if(d[i]==1){
                //cout<<task[i]<<" ";
                ctr++;
                sum+=task[i];
                if(task[i]>hrd){
                    hrd = task[i];
                }
                if(task[i]<eas){
                    eas = task[i];
                }
            }
        }
        //cout<<endl;
        if(sum<=r && sum>=l && hrd-eas>=x && ctr>=2){
            
            return 1;
        }else{
            return 0;
        }
    }else{
        int ans=0;
        for(int i = 0;i<2;i++){
            d[cur] = i;
            ans+=bits(task,n,cur+1,l,r,x);
        }
        return ans;
    }
}


int main(){
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    int c[n];
    int prefix[n+1];
    for(int i =0;i<n;i++){
        cin>>c[i];
    }
    int d[n];
    int ctr = bits(c,n,0,l,r,x);
    cout<<ctr/2<<endl;
    return 0;
}