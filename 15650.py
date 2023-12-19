import sys

input = sys.stdin.readline
N, M = map(int, input().split())
visit = [0 for i in range(M)]


def backtracking(std,level):
    if level==M:
        for i in visit:
            print(i+1,end=" ")
        print()
        return
    else:
        for i in range(std,N):
            visit[level]=i
            # 현재 시점에서 그 다음으로
            backtracking(i+1,level+1)
backtracking(0,0)
