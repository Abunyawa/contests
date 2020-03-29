#include<bits/stdc++.h>
#define line1 ios_base::sync_with_stdio(0)
#define line2 cin.tie(0);
using namespace std;
 

int main(){

    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    set<pair<int,int> > sr;

    int l=0,r=0;
    int ctr = 0;
    while(l<=r && r<n){
        while(sr.size()<=k+1 && r<=n){
            //cout<<'1'<<endl;
            auto it = sr.end();
            for(auto i=sr.begin();i!=sr.end();i++){
                pair<int,int> cur = *i;
                if(cur.first==a[r]){
                    it = i;
                }
            }
            if (it != sr.end()){
                pair<int,int> cur = *it;
                int num = cur.second;
                sr.erase(it);
                sr.insert(make_pair(a[r],num+1));
            }else{
                //cout<<'3'<<endl;
                sr.insert(make_pair(a[r],1));
            }
            r++;
        }
        sr.erase(sr.find(make_pair(a[r-1],1)));
        r--;

        for(auto i=sr.begin();i!=sr.end();i++){
            pair<int,int> cur = *i;
            
            if(cur.second>ctr){
                ctr=cur.second;
            }
        }

        while(sr.size()==k+1 && l<r){
            //cout<<'2'<<endl;
            auto it = sr.end();
            for(auto i=sr.begin();i!=sr.end();i++){
                pair<int,int> cur = *i;
                if(cur.first==a[l]){
                    it = i;
                }
            }
            if (it != sr.end()){
                pair<int,int> cur = *it;
                int num = cur.second;
                if(num==1)
                    sr.erase(it);
                else{
                    sr.erase(it);
                    sr.insert(make_pair(a[l],num-1));
                }
            }
            l++;
        }
    }
    printf("%d",ctr);
    
    return 0;
}