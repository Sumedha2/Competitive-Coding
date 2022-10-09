#https://www.codechef.com/submit/VACCINE2
#Vaccine Distribution
#VACCINE2
#DEC20
t=int(input())
for i in range(t):
    n, d=map(int, input().strip().split())
    arr2=list(map(int, input().strip().split()))
    if d==1 or n==1:
        print(n)
    else:
        li=[]
        arr=[]
        for i in range(len(arr2)):
            if arr2[i]<=9 or arr2[i]>=80:
                li.append(arr2[i])
            else:
                arr.append(arr2[i])
            len1=len(arr)
            len2=len(li)
            if len1%d==0:
                c=int(len1/d)
            else:
                c=int(len1/d)+1
            if len2%d==0:
                e=int(len2/d)
            else:
                e=int(len2/d)+1
        print(c+e)


