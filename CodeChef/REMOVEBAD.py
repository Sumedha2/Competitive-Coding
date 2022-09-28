#https://www.codechef.com/submit/REMOVEBAD
t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int, input().strip().split()))
    maparr = dict.fromkeys(arr, 0)
    for i in range(n):
        maparr[arr[i]]+=1
    li=[]
    for i in maparr:
        li.append(maparr[i])
    maxi=max(li)
    if n==1:
        print(0)
    else:
        print(n-maxi)