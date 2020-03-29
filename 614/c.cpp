#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    set<pair<int,int> > s;
    int blocks = 0;

    for(int i=0;i<q;i++){
        int x, y;
        cin>>y>>x;
        if(s.find(make_pair(x,y))==s.end()){
            s.insert(make_pair(x,y));
            if(y==1){
                for(int j=-1;j<2;j++){
                    if(x+j>0 && x+j<=n){
                        pair<int,int> mb = make_pair(x+j,2);
                        if(s.find(mb)!=s.end()){
                            blocks++;
                        }
                    }
                }
            }else{
                for(int j=-1;j<2;j++){
                    if(x+j>0 && x+j<=n){
                        pair<int,int> mb = make_pair(x+j,1);
                        if(s.find(mb)!=s.end()){
                            blocks++;

                        }
                    }
                }
            }
        }else{
            s.erase(make_pair(x,y));
            if(y==1){
                for(int j=-1;j<2;j++){
                    if(x+j>0 && x+j<=n){
                        pair<int,int> mb = make_pair(x+j,2);
                        if(s.find(mb)!=s.end()){
                            blocks--;

                        }
                    }
                }
            }else{
                for(int j=-1;j<2;j++){
                    if(x+j>0 && x+j<=n){
                        pair<int,int> mb = make_pair(x+j,1);
                        if(s.find(mb)!=s.end()){
                            blocks--;

                        }
                    }
                }
            }
        }
        if(blocks==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;

        }
    }
    
    
    return 0;
}