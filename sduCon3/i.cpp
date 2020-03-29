#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
const int INF = 1000010;


long long t[4*MAXN],a[MAXN], t2[4*MAXN];

void push(int v, int tl, int tr){
    if(t2[v]==-1) return;
    int tm = (tl+tr)/2;
    t[v*2] = t2[v];
    t2[v*2] = t2[v];
    t[v*2+1] = t2[v];
    t2[v*2+1] = t2[v];
    t2[v] = -1;
}
void build(int v, int tl, int tr){
    if(tl==tr){
        t[v] = a[tl];
        return;
    }else{
        int tm = (tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        t[v] = min(t[2*v],t[2*v+1]);
        return;
    }
}


void add(int v, int tl, int tr, int l, int r, long long x){
    if(tr<l || r < tl){
        return;
    }
    if(l<=tl && tr<=r){

        t[v]=x;
        t2[v]=x;
        return; 
    }
    //push(v,tl,tr);
    int tm = (tl+tr)/2;
    add(v*2,tl, tm,l,r,x);
    add(v*2+1,tm+1,tr,l,r,x);
    t[v] = min(t[v*2],t[v*2+1]);
}

void change(int v, int tl, int tr, int pos, long long x){
    if(tr<pos || pos < tl){
        return;
    }
    if(tl==tr){
        a[tl]=x;
        t[v]=x;
        return; 
    }
    int tm = (tl+tr)/2;
    change(v*2,tl, tm,pos,x);
    change(v*2+1,tm+1,tr,pos,x);
    t[v] = min(t[v*2],t[v*2+1]);
}
long long sum(int v, int tl, int tr, int l, int r){
    if(tr<l || r<tl){
        return INT_MAX;
    }
    if(l <= tl && tr <= r){
        return t[v];
    }
    //push(v,tl,tr);
    int tm = (tl+tr)/2;
    long long sl = sum(v*2,tl,tm,l,r);
    long long sr = sum(v*2+1,tm+1,tr,l,r);
    return min(sl,sr);

}
struct qr{
    long long l,r,x;
};
bool cmp(qr a, qr b){
    return a.x < b.x;
}



int main(){
    ifstream fin("exam.in");
    ofstream fout("exam.out");
    int n;
    fin>>n;
    for(int i=1;i<=MAXN;i++){
        a[i] = i;
        //cout<<a[i]<<" ";
    }
    
    build(1,1,MAXN);
    
    for(int i=0;i<n;i++){
        int x;
        fin>>x;
        if(x>0){
            long long pos = sum(1,1,MAXN,x,MAXN);
            //cout<<pos<<endl;
            change(1,1,MAXN,pos,INF);
           
            fout<<pos<<endl;
        }else{
            change(1,1,MAXN,-x,-x);
        }
    }
    return 0;
}