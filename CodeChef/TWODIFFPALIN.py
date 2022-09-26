#https://www.codechef.com/submit/TWODIFFPALIN
t=int(input())
for i in range(t):
    a, b=map(int, input().strip().split())
    if (a%2!=0) and (b%2!=0):
        print('no')
    elif ((a==1) or (b==1)):
        print('no')
    else:
        print('yes')