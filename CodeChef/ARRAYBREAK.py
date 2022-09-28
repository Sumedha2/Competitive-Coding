#https://www.codechef.com/submit/ARRAYBREAK
t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int, input().strip().split()))
    even=0
    for i in arr:
        if i%2==0 and i!=0:
            even+=1
    if even==n:
        print(0)
    else:
        print(even)
    
    