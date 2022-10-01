#https://www.codechef.com/submit/SC31
#NOV19
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    s2=""
    for j in range(n-1):
        s1=input()
        for i in range(10):
            if s[i]==s1[i]:
                s2=s2+'0'
            else:
                s2=s2+'1'
        s=s2
        s2=""
    print(s.count('1'))
