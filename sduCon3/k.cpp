#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;

long long t[4*MAXN],a[MAXN], t2[4*MAXN];

void push(int v, int tl, int tr){
    if(t2[v]==-1) return;
    int tm = (tl+tr)/2;
    t[v*2] = t2[v]*(tm-tl+1);
    t2[v*2] = t2[v];
    t[v*2+1] = t2[v]*(tr-tm);
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
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
}


void add(int v, int tl, int tr, int l, int r, long long x){
    if(tr<l || r < tl){
        return;
    }
    if(l<=tl && tr<=r){

        t[v]=(tr-tl+1)*x;
        t2[v]=x;
        return; 
    }
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    add(v*2,tl, tm,l,r,x);
    add(v*2+1,tm+1,tr,l,r,x);
    t[v] = t[v*2]+t[v*2+1];
}
/*
void change(int v, int tl, int tr, int pos, long long x){
    if(tr<pos || pos < tl){
        return;
    }
    if(tl==tr){
        a[tl]+=x;
        t[v]+=x;
        return; 
    }
    int tm = (tl+tr)/2;
    change(v*2,tl, tm,pos,x);
    change(v*2+1,tm+1,tr,pos,x);
    t[v] = t[v*2]+t[v*2+1];
}*/
long long sum(int v, int tl, int tr, int l, int r){
    if(tr<l || r<tl){
        return 0;
    }
    if(l <= tl && tr <= r){
        return t[v];
    }
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    long long sl = sum(v*2,tl,tm,l,r);
    long long sr = sum(v*2+1,tm+1,tr,l,r);
    return sl+sr;

}

int main(){
    
    ifstream fin("sum.in");
    ofstream fout("sum.out");

    int n,k;
    fin>>n>>k;

    for(long long i=1;i<=n;i++){
        a[i] = 0;
    }
    for(long long i=1;i<=n*4;i++){
        t2[i] = -1;
        t[i]=-1;
    }
    build(1,1,n);
    for(long long i=0;i<k;i++){
        char a;
        fin>>a;
        if(a=='A'){
            int l,r;
            long long x;
            fin>>l>>r>>x;
            add(1,1,n,l,r,x);
        }else{
            int l,r;
            fin>>l>>r;
            long long ans = sum(1,1,n,l,r);
            fout<<ans<<endl;
        }
    }

    return 0;
}