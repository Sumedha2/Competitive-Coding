#https://www.codechef.com/submit/NONNEGPROD
t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int, input().strip().split()))
    c=0
    for i in arr:
        if i<0:
            c+=1 
        if i==0:
            c=2
            break
    if c%2==0:
        print(0)
    else:
        print(1)