#include<bits/stdc++.h>
using namespace std;
int al[26][26];


int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int cur = 0;
    char letter1,letter2;
    for(int i = 0;i<n-1;i++){
        al[(int)(str[i]-'A')][(int)(str[i+1]-'A')]++;
        if(al[(int)(str[i]-'A')][(int)(str[i+1]-'A')]>cur){
            cur = al[(int)(str[i]-'A')][(int)(str[i+1]-'A')];
            letter1 = str[i];
            letter2 = str[i+1];
        }
    }
    cout<<letter1<<letter2<<endl;
    return 0;
}






