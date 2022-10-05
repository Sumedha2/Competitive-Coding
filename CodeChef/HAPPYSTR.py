#https://www.codechef.com/submit/HAPPYSTR
#Chef and Happy String
#START59
t=int(input())
for i in range(t):
    s=input()
    s.lower()
    arr=[]
    for i in range(len(s)):
        if s[i]!='a' and s[i]!='e' and s[i]!='i' and s[i]!='o' and s[i]!='u':
            arr.append(i)
    arr2=[]
    for i in range(len(arr)-1):
        arr2.append(abs(arr[i]-arr[i+1]))
    c=0
    for i in arr2:
        if i>=4:
            c=1
    if len(arr)==0:
        print('happy')
    elif arr[0]>=3:
        print('happy')
    elif (len(s)-arr[-1])>=4:
        print('happy')
    elif c==1:
        print('happy')
    else:
        print('sad')