#https://www.codechef.com/submit/STICKBREAK
t=int(input())
for i in range(t):
    l, k=map(int, input().strip().split())
    m=l%k 
    if m==0:
        print(m)
    else:
        print(1)
        