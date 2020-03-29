#include<bits/stdc++.h>
using namespace std;
struct S{
    int st[3];
    int n;
    int wins = 0;
};

bool cmp(S a, S b){
    int a1=0, b1=0;
    for(int i=0;i<3;i++){
        if(a.st[i]>b.st[i]){
            a1++;
        }else{
            b1++;
        }
    }
    return a1<b1;
}

int main(){
    int n;
    cin>>n;
    vector<S> sit;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        S k;
        k.st[0]=a;
        k.st[1]=b;
        k.st[2]=c;
        k.n = i+1;
        
        sit.push_back(k);
        
    }
    sort(sit.begin(),sit.end(),cmp);
    int wn =0;
    for(int i=1;i<n;i++){
        if(!cmp(sit[0],sit[i])){
            wn++;
        }
    }
    
    if(wn==0){
        cout<<1<<endl;
        cout<<sit[0].n<<endl;
    }else{
        cout<<0<<endl;
    }
 
   
    return 0;
}