#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        vector<long long> nt1;
        vector<long long> nt2;
        int cnt=0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            cin>>a[i];
            /*
            int toL = i;
            int toR = n-1-i;
            if(a[i]<toL || a[i] < toR){
                flag = false;
            }
            */
           if(a[i]>=cnt && nt2.empty()){
               nt1.push_back(i);
               cnt++;
           }else{
               nt2.push_back(i);
               if(a[i]==a[i-1]){
                   a[i]--;
               }
               if(a[i]<n-1-i){
                   flag = false;
               }
           }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

        
    }


    return 0;
}