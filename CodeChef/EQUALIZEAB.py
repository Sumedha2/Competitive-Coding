#https://www.codechef.com/submit/EQUALIZEAB
t=int(input())
for i in range(t):
    a, b, x=map(int, input().strip().split())
    if a>b:
        temp=a
        a=b 
        b=temp
    m=b-a
    if m%x==0:
        m1=m/x 
        if m1%2==0:
            print('yes')
        else:
            print('no')
    else:
        print('no')