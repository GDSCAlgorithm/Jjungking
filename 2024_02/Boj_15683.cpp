#include <bits/stdc++.h>

using namespace std;
int N,M;
int arr[9][9];
vector<pair<int,int>> cctv;
int cnt;
int ans = INT_MAX;
int dirX[4]={0,-1,0,1};
int dirY[4]={1,0,-1,0};

void check(int x,int y,int dir){
    dir%=4; // 만약 dir가 4인경우 0이되어야함!
    while(true){
        int nx = x+dirX[dir];
        int ny = y+dirY[dir];
        x=nx;
        y=ny;
        if(nx<0||nx>=N||ny<0||ny>=M){
            return;
        }
        if(arr[nx][ny]==6){
            return;
        }
        if(arr[nx][ny]!=0){
            continue;
            
        }
        arr[nx][ny]=-1;

    }

}
void dfs(int idx){
    if(idx==cnt){
        int res = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j]==0){
                    res++;
                }
            }
        }
        ans = min(res,ans);
        return;
    }
    // 회전 갈기기
    int backup[9][9];
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    for(int dir=0;dir<4;dir++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                backup[i][j]=arr[i][j];
            }
        }
        if(arr[x][y]==1){
            check(x,y,dir);
        }
        if(arr[x][y]==2){
            check(x,y,dir);
            check(x,y,dir+2);

        }
        if(arr[x][y]==3){
            check(x,y,dir);
            check(x,y,dir+1);

        }
        if(arr[x][y]==4){
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
        }
        if(arr[x][y]==5){
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
            check(x,y,dir+3);
        }
        dfs(idx+1);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                arr[i][j]=backup[i][j];
            }
        }
        
    }


}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(1<=arr[i][j]&&arr[i][j]<=5){
                cctv.push_back({i,j});
            }
        }
    }
    cnt = cctv.size();
    dfs(0);
    cout<<ans<<endl;

}