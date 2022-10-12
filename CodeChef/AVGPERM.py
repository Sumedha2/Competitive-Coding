# https://www.codechef.com/problems/AVGPERM
# Average Permutation
#AVGPERM
# Practice
t=int(input())
for i in range(t):
    n=int(input())
    li1=[]
    li2=[]
    i=n
    while(i>=1):
        if i%2==0:
            li1.append(i)
        else:
            li2.append(i)
        i-=1
    li2.sort()
    li=li1+li2
    s=' '.join(str(i) for i in li)
    print(s)