#https://www.codechef.com/submit/EVENSPLIT
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    zero=''
    one=''
    for i in s:
        if i=='0':
            zero=zero+i
        else:
            one=one+i
    ans=zero+one
    if n<3:
        ans=s
    print(ans)