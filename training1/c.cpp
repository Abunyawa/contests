#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int red=0, inc = 0;
    for(int i=0;i<n;i++){
        if(a[i]>b[i]){
            red++;
        }
        if(a[i]<b[i]){
            inc++;
        }
    }
    if(inc==red && inc==0){
        cout<<"Unchanged"<<endl;
    }else if(inc==0){
        cout<<"Reduced"<<endl;
    }else if(red==0){
        cout<<"Increased"<<endl;
    }else{
        cout<<"Rescaled"<<endl;
    }

    return 0;
}