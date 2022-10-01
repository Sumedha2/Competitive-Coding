#https://www.codechef.com/submit/HOWMANYMAX
#START42
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    c=1
    for i in range((len(s))-1):
        if s[i]=='1' and s[i+1]=='0':
            c+=1
    print(c)