#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> num(n);
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+= (int)(num[i]-'0');
        }
        while((int)(num[n-1]-'0')%2==0 && n>0){
            sum-=(int)(num[n-1]-'0');
            n--;
        }
        if(n>0){
            if(sum%2==0){
                for(int i=0;i<n;i++){
                    cout<<num[i];
                }
                cout<<endl;
            }else{
                for(int j=n-2;j>=0;j--){
                    if((int)(num[j]-'0')%2==1){
                        sum-=(int)(num[j]-'0');
                        n--;
                        num.erase(num.begin()+j);
                        break;

                    }
                }
                if(sum%2==0){
                    for(int i=0;i<n;i++){
                        cout<<num[i];
                    }
                    cout<<endl;
                }else{
                    cout<<-1<<endl;
                }
            }
        }else{
            cout<<-1<<endl;
        }
    }


    return 0;
}