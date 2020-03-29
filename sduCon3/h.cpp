#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
 
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
        t[v] = INT_MAX;
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
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    add(v*2,tl, tm,l,r,x);
    add(v*2+1,tm+1,tr,l,r,x);
    t[v] = min(t[v*2],t[v*2+1]);
}
 
void change(int v, int tl, int tr, int l,int r, long long x){
    if(tr<l || r < tl){
        return;
    }
    if(tl==tr){
        t[v]=x;
        return; 
    }
    int tm = (tl+tr)/2;
    change(v*2,tl, tm,l,r,x);
    change(v*2+1,tm+1,tr,l,r,x);
    t[v] = min(t[v*2],t[v*2+1]);
}
long long sum(int v, int tl, int tr, int l, int r){
    if(tr<l || r<tl){
        return INT_MAX;
    }
    if(l <= tl && tr <= r){
        return t[v];
    }
    push(v,tl,tr);
    int tm = (tl+tr)/2;
    long long sl = sum(v*2,tl,tm,l,r);
    long long sr = sum(v*2+1,tm+1,tr,l,r);
    return min(sl,sr);
 
}
struct qr{
    long long l,r,x;
};
bool cmp(qr a, qr b){
    return a.r < b.r;
}
 
 
 
int main(){
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");
    int n,m;
    fin>>n>>m;
    vector<qr> q;
    for(int i=0;i<m;i++){
        long long l,r,x;
        fin>>l>>r>>x;
        qr s;
        s.l=l;
        s.r=r;
        s.x=x;
        q.push_back(s);
    }
    sort(q.begin(),q.end(),cmp);
    
    
    
 
    for(long long i=0;i<m;i++){
        long long l,r,x;
        l = q[i].l;
        r = q[i].r;
        x = q[i].x;
        //cout<<l<<' '<<r<<endl;
        for(int i=l;i<=r;i++){
            a[i] = x;
        }
        
    }
    bool flag = true;



    
    build(1,1,n);
    for(int i=0;i<m;i++){
        long long l,r,x;
        l = q[i].l;
        r = q[i].r;
        x = q[i].x;
        long long q1 = sum(1,1,n,l,r);
        if(q1!=x){
            fout<<"inconsistent"<<endl;
            break;
        }
    }
 
    fout<<"consistent"<<endl;
    for(int i=1;i<=n;i++){
        fout<<sum(1,1,n,i,i)<<' ';
    }
    fout<<endl;
    
 
    return 0;
}