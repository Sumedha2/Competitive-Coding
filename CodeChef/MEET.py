#https://www.codechef.com/FEB21C/problems/MEET
#Chef and Meetings
#FEB21C
def time(t):
    sol=0
    if 'PM' in t:
        if t[:2]!='12':
            sol=(int(t[:2])+12)*60+int(t[3:5])
        else:
            sol=720+int(t[3:5])
    else:
        if t[:2]!='12':
            sol=int(t[:2])*60+int(t[3:5])
        else:
            sol=int(t[3:5])
    return sol
for _ in range (int(input())):
    t=''
    s=input()
    s=time(s)
    n=int(input())
    for i in range(n):
        t1=input()
        t2=time(t1[:8])
        t3=time(t1[9:])
        if s>=t2 and s<=t3:
            t+='1'
        elif t3<t2 and (s>=t3 or  s<=t2):
            t+='1'
        else:
            t+='0'
    print(t)
            
            
         
    