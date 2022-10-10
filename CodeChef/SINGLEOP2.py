#https://www.codechef.com/OCT221D/problems/SINGLEOP2
#Single Operation Part 2
#SINGLEOP2
#OCT221D
t=int(input())
for i in range(t):
    n=int(input())
    s=input()
    s=s[1:]
    zero=1
    for i in s:
        if i=='0':
            zero+=1
        else:
            break
    print(zero)