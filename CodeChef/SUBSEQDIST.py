# https://www.codechef.com/submit/SUBSEQDIST
import math
t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int, input().strip().split()))
    maparr = dict.fromkeys(arr, 0)
    for i in range(n):
        maparr[arr[i]]+=1
    maxi=max(maparr.values())
    maxi=math.ceil(math.log(maxi, 2))
    print(maxi)