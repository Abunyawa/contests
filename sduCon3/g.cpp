#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

long long t[4*MAXN],a[MAXN+10], t2[4*MAXN],a2[MAXN+10];



void build(int v, int tl, int tr){
    if(tl==tr){
        t[v] = a[tl];
        return;
    }else{
        int tm = (tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        t[v] = max(t[2*v],t[2*v+1]);
        return;
    }
}

void build2(int v, int tl, int tr){
    if(tl==tr){
        t2[v] = a[tl];
        return;
    }else{
        int tm = (tl+tr)/2;
        build2(2*v,tl,tm);
        build2(2*v+1,tm+1,tr);
        t2[v] = min(t2[2*v],t2[2*v+1]);
        return;
    }
}

/*
void add(int v, int tl, int tr, int l, int r, int x){
    if(tr<l || r < tl){
        return;
    }
    if(l<=tl && tr<=r){

        t[v]+=(tr-tl+1)*x;
        t2[v]+=x;
        return; 
    }
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    add(v*2,tl, tm,l,r,x);
    add(v*2+1,tm+1,tr,l,r,x);
    t[v] = max(t[v*2],t[v*2+1]);
}*/
void change(int v, int tl, int tr, int pos, int x){
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
    t[v] = max(t[v*2],t[v*2+1]);
}

void change2(int v, int tl, int tr, int pos, int x){
    if(tr<pos || pos < tl){
        return;
    }
    if(tl==tr){
        a2[tl]=x;
        t2[v]=x;
        return; 
    }
    int tm = (tl+tr)/2;
    change2(v*2,tl, tm,pos,x);
    change2(v*2+1,tm+1,tr,pos,x);
    t2[v] = min(t2[v*2],t2[v*2+1]);
}
long long sum(int v, int tl, int tr, int l, int r){
    if(tr<l || r<tl){
        return -999999999999;
    }
    if(l <= tl && tr <= r){
        return t[v];
    }
    //push(v,tl,tr);
    int tm = (tl+tr)/2;
    long long sl = sum(v*2,tl,tm,l,r);
    long long sr = sum(v*2+1,tm+1,tr,l,r);
    return max(sl,sr);

}
long long sum2(int v, int tl, int tr, int l, int r){
    if(tr<l || r<tl){
        return 999999999999;
    }
    if(l <= tl && tr <= r){
        return t2[v];
    }
    //push(v,tl,tr);
    int tm = (tl+tr)/2;
    long long sl = sum2(v*2,tl,tm,l,r);
    long long sr = sum2(v*2+1,tm+1,tr,l,r);
    return min(sl,sr);

}
int main(){
    ifstream fin("rvq.in");
    ofstream fout("rvq.out");

    int n=100001,k;
    fin>>k;

    for(long long i=1;i<=n;i++){
        a[i] =((i%12345)*(i%12345))%12345+(((i%23456)*(i%23456)%23456*(i%23456))%23456);
        a2[i] = a[i];
       
    }
    build(1,1,n);
    build2(1,1,n);
    for(int i=0;i<k;i++){
        int x,y;
        fin>>x>>y;
        if(x>0){
            fout<<sum(1,1,n,x,y)-sum2(1,1,n,x,y)<<endl;
        }else{
            change(1,1,n,abs(x),y);
            change2(1,1,n,abs(x),y);
        }
    }

    return 0;
}