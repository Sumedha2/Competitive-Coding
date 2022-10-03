#https://www.codechef.com/submit/RECNDSTR
#RC122020
t=int(input())
for i in range(t):
    s=input()
    lv=s[1:]+s[0]
    rv=s[-1]+s[:-1]
    if lv==rv:
        print('YES')
    else:
        print('NO')
        