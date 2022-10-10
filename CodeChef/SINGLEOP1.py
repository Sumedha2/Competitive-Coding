#https://www.codechef.com/OCT221D/problems/SINGLEOP1
#Single Operation Part 1
#SINGLEOP1
#OCT221D
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    one=0
    for i in s:
        if i=='1':
            one+=1
        else:
            break
    print(one)