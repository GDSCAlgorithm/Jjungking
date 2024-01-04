import sys
input = sys.stdin.readline

N = int(input())
lst=[ int(input())for _ in range(N)]
dp = [0 for _ in range(N)]
dp[0]=lst[0]
for i in range(1,N):
    if i==1:
        dp[i]=lst[0]+lst[1]
    elif i==2:
        dp[i]=max(lst[0]+lst[2],lst[1]+lst[2])
    else:
        dp[i] = max(lst[i] + dp[i - 2], lst[i] + lst[i - 1] + dp[i - 3])

print(dp[-1])

