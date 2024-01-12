import sys

input = sys.stdin.readline
N = int(input())
M = int(input())
lst = [[0 for i in range(3)] for j in range(M)]
parent = [0 for _ in range(N + 1)]
for i in range(1, N + 1):
    parent[i] = i
total = 0

for i in range(M):
    start, end, cost = map(int, input().split())
    lst[i][0] = start
    lst[i][1] = end
    lst[i][2] = cost


def check_node(x, y):
    if parent[x] != parent[y]:
        return True
    return False

def find_parent(x):
    if parent[x] == x:
        return x
    else:
        y = find_parent(parent[x])
        parent[x] = y
        return parent[x]


def union(x, y,cost):
    global total
    m = find_parent(x)
    n = find_parent(y)
    if check_node(m,n):
        if m < n:
            parent[n] = m
        else:
            parent[m] = n
        total+=cost

lst.sort(key=lambda x: x[2])
for i in range(len(lst)):
    start = lst[i][0]
    end = lst[i][1]
    cost = lst[i][2]
    if check_node(start, end):
        union(start, end,cost)

print(total)