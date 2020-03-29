#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("o.txt","w",stdout);
    int n;
    cin>>n;
    vector<long long> a(n);
    long long odd(0);
    long long even(0);
    int odd1(1),even1(2);

    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i%2==0){
            even+=a[i];
        }else{
            odd+=a[i];
        }

    }
    even1 = 1;
    odd1 = 2;
    vector<int> ans1;
    long long sum=0;
    long long evenz = even;
    long long oddz = odd;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(flag && even*even1+odd*odd1>a[i]*max(3,(ans1[ans1.size()-1]+1))+(even-a[i])*odd1+odd*even1){
                int nm = max(3,(ans1[ans1.size()-1]+1));
                for(int j=0;j<a[i];j++){
                    ans1.push_back(nm);
                    sum+=nm;
                }
                int tmp = even1;
                even1 = odd1;
                odd1 = tmp;
                flag = false;
            }else{
                for(int j=0;j<a[i];j++){
                    ans1.push_back(even1);
                    sum+=even1;
                }
                flag = true;
            }

            
            even-=a[i];
        }else{
            if(flag && even*even1+odd*odd1>a[i]*max(3,(ans1[ans1.size()-1]+1))+even*odd1+(odd-a[i])*even1){
                int nm = max(3,(ans1[ans1.size()-1]+1));
                for(int j=0;j<a[i];j++){
                    ans1.push_back(nm);
                    sum+=nm;
                }
                int tmp = even1;
                even1 = odd1;
                odd1 = tmp;
                flag = false;
            }else{
                for(int j=0;j<a[i];j++){
                    ans1.push_back(odd1);
                    sum+=odd1;
                }
                flag = true;
            }
            odd-=a[i];
        }
    }
    ans1.push_back(sum);
    sum = 0;
    even = evenz;
    odd = oddz;
    even1 = 2;
    odd1 = 1;
    flag  = false;
    vector<int> ans2;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(flag && even*even1+odd*odd1>=a[i]*max(3,(ans2[ans2.size()-1]+1))+(even-a[i])*odd1+odd*even1){
                int nm = max(3,(ans2[ans2.size()-1]+1));
                for(int j=0;j<a[i];j++){
                    ans2.push_back(nm);
                    sum+=nm;
                }
                int tmp = even1;
                even1 = odd1;
                odd1 = tmp;
                flag = false;
            }else{
                for(int j=0;j<a[i];j++){
                    ans2.push_back(even1);
                    sum+=even1;
                }
                flag = true;
            }

            
            even-=a[i];
        }else{
            if(flag && even*even1+odd*odd1>=a[i]*max(3,(ans2[ans2.size()-1]+1))+even*odd1+(odd-a[i])*even1){
                int nm = max(3,(ans2[ans2.size()-1]+1));
                for(int j=0;j<a[i];j++){
                    ans2.push_back(nm);
                    sum+=nm;
                }
                int tmp = even1;
                even1 = odd1;
                odd1 = tmp;
                flag = false;
            }else{
                for(int j=0;j<a[i];j++){
                    ans2.push_back(odd1);
                    sum+=odd1;
                }
                flag = true;
            }
            odd-=a[i];
        }
    }
    ans2.push_back(sum);

    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<' ';
    }
    if(ans1[ans1.size()-1]<ans2[ans2.size()-1]){
        
    }else{
        
    }

    cout<<endl;
    return 0;
}