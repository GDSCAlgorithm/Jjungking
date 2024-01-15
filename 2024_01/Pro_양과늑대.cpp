#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
vector<int> arr[18];
vector<int> infoVector;
int answer=0;

void dfs(int node,int sheep,int wolf,queue<int>q){
    
    if(infoVector[node]==0){
        sheep+=1;
    }else{
        wolf+=1;
    }
    if(wolf>=sheep){

        return;
    }
    answer=max(answer,sheep);
    for(int i=0;i<arr[node].size();i++){
        q.push(arr[node][i]); // 0->2->5->6 같은 경우 0->2->6이 되지 않게
    }

    for(int i=0;i<q.size();i++){
       
        int next = q.front();
        q.pop();
        dfs(next,sheep,wolf,q);
        q.push(next);
    }

}
int solution(vector<int> info, vector<vector<int>> edges) {

 
    for(int i=0;i<edges.size();i++){
        int parent = edges[i][0];
        int child = edges[i][1];

        arr[parent].push_back(child);

    }
    infoVector.assign(info.begin(),info.end());
    queue<int> q;
    dfs(0,0,0,q);
    
  
    return answer;
}

