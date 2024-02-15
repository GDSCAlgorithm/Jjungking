#include <bits/stdc++.h>

using namespace std;
stack<int>s[7];
int cnt;
int n,p;
int main(){
    cin>>n>>p;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(s[a].empty()){
            s[a].push(b);
            cnt++;
        }else if(s[a].top()<b){
            s[a].push(b);
            cnt++;
        }else if(s[a].top()>b){
            while(s[a].top()>b){
                s[a].pop();
                cnt++;
                // 비어 있는 경우도 확인해야! 그리고 pop하고 나서 바로 체크해줘야지
                // 안그러면 아예 비어있는 상태에서 top()하면 seg fault
                if(s[a].empty()){
                    cnt++;
                    s[a].push(b);
                }
            }
            if(s[a].top()<b){
                s[a].push(b);
                cnt++;
            }
        }

        
    }
    cout<<cnt<<endl;
    

}