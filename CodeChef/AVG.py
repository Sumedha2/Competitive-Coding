#https://www.codechef.com/submit/AVG
#LTIME69
t=int(input())
for i in range(t):
    n, k, v=map(int, input().strip().split())
    arr=list(map(int, input().strip().split()))
    x=(v*(n+k)-sum(arr))/k
    if x>0 and x==int(x):
        print(int(x))
    else:
        print(-1)