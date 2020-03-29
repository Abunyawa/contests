#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<char> q1;
    vector<char> q2;
    vector<char> q;
    bool flag = true;
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        q.push_back(a);
        if(q1.empty()){
            q1.push_back(a);
        }else{
            if(q1[q1.size()-1]<=a){
                q1.push_back(a);
            }else{
                if(q2.empty()){
                    q2.push_back(a);
                }else if(q2[q2.size()-1]<=a){
                    q2.push_back(a);
                }else{
                    flag = false;
                    break;
                }
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            if(q[i] == q1.front()){
                q1.erase(q1.begin());
                cout<<0;
            }else{
                q2.erase(q2.begin());
                cout<<1;
            }
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}