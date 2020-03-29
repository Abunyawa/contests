#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;

int t[4*MAXN],a[MAXN], t2[4*MAXN];


int main(){
    int n;
    cin>>n;
    vector<int> a(10,0);
    for(int i = 0;i<n;i++){
        char c;
        cin>>c;
        if(c=='L'){
            int k=0;
            while(a[k]!=0){
                k++;
            }
            a[k]=1;
        }else if(c=='R'){
            int k=9;
            while(a[k]!=0){
                k--;
            }
            a[k]=1;
        }else{
            a[(int)(c-'0')]--;
        }
    }
    for(int i = 0;i<10;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}