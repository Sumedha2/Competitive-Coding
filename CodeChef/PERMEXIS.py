#https://www.codechef.com/submit/PERMEXIS
#COOK75
t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int, input().strip().split()))
    arr.sort()
    c=1
    for i in range(n):
        if arr[i]-arr[i-1]>1:
            c=0
            break
    if c==1:
        print('YES')
    else:
        print('NO')
