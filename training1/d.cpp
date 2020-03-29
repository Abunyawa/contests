#include<bits/stdc++.h>

using namespace std;
struct cp{
    int tp;
    long long l,r;
};

int main(){
    long long n,m;
    cin>>n>>m;
    vector<cp> q;
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        long long l,r;
        cin>>l>>r;
        if(str=="inverse"){
            cp nw;
            nw.tp = 1;
            nw.l = l;
            nw.r = r;
            q.push_back(nw);
        }else{
            cp nw;
            nw.tp = 2;
            nw.l = l;
            nw.r = r;
            q.push_back(nw);
        }
    }
    
    long long pos;
    cin>>pos;
    bool min = true;
    for(int i=m-1;i>=0;i--){
        if(pos>=q[i].l && pos<=q[i].r){
            if(q[i].tp == 1){
                min = !min;
            }else{
                long long shift = q[i].r-pos;
                pos = q[i].l+shift;
            }
        }
    }
    if(!min){
        pos*=-1;
    }
    cout<<pos<<endl;
    return 0;
}