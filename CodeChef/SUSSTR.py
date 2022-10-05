#https://www.codechef.com/submit/SUSSTR
#Suspense String
#START59
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    t=''
    while len(s)>0:
        if s[0]=='0':
            t=s[0]+t
            s=s[1:]
        else:
            t=t+s[0]
            s=s[1:]
        if len(s)>0:
            if s[-1]=='1':
                t=s[-1]+t
                s=s[:-1]
            else:
                t=t+s[-1]
                s=s[:-1]
    print(t)
