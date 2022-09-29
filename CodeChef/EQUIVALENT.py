#https://www.codechef.com/submit/EQUIVALENT
import math
t=int(input())
for i in range(t):
    a_, b_=map(int, input().strip().split())
    a=max(a_, b_)
    b=min(a_, b_)
    c=(math.log(a)/math.log(b))
    ans=0
    for i in range(0, 50):
        if (c-int(c)<(10**(-8))):
            ans=1
            break
        c=1/(c-int(c))
    if ans==1:
        print('yes')
    else:
        print('no')
        
