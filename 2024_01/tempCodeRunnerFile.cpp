#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<pair<int,int>,int>> v;
vector<pair<pair<int,int>,int>> copyV;

int cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){

    if(a.first.first>b.first.first && a.first.second>b.first.second){
        return true;
    }
    return false;

}

int main(){
    cin>>N;

    for(int i=0;i<N;i++){
        int weight,height;
        cin>>weight>>height;
        v.push_back({{weight,height},0});
        copyV.push_back({{weight,height},0});
    }

  
    sort(v.begin(),v.end(),cmp);

    int idx=1;
    v[0].second=1;
    for(int i=1;i<N-1;i++){
        if(v[i].first.first<v[i-1].first.first&&v[i].first.second<v[i-1].first.second){
            v[i].second=i+1;
            idx++;
        }else{
            v[i].second=idx;
        }

    }
     if(v[N-2].first.first>v[N-1].first.first&&v[N-2].first.second>v[N-1].first.second){
            v[N-1].second=N;
            idx++;
    }else{
        v[N-1].second=idx;
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(v[i].first.first==copyV[j].first.first){
       
                copyV[j].second=v[i].second;
            }
        }
    }

    for(int i=0;i<N;i++){

        cout<<copyV[i].second<<" ";
    }
  
}