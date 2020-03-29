#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int lcm(int a, int b) 
{ 
    return (a * b) / gcd(a, b); 
} 

int main(){
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int r,b,k;
        cin>>r>>b>>k;
        int lcm1 = lcm(r,b);
        bool color = true;
        int counter(1);
        int maxPtr = max(r,b);
        int arr[lcm1];
        int ptr1 = 0;
        int ptr2 = 0;
        for(int i = 0;i<lcm1;i++){

            if(ptr1<ptr2){
                arr[i] = ptr1;
                if(arr[i-1]%r==0) counter++;
                else counter = 1;
                ptr1+=r;
            }else if(ptr2<ptr1){
                arr[i] = ptr2;
                if(arr[i-1]%b==0) counter++;
                else counter = 1;
                ptr2+=b;
            }else{
                arr[i] = ptr1;
                counter = 1;
                ptr1+=r;
                ptr2+=b;
            }
        }

        for(int i=0;i<lcm1;i++){

        }
        if(counter>=k){
            cout<<"REBEL"<<endl;
        }else{
            cout<<"OBEY"<<endl;            
        }
       
    }
    return 0;
}