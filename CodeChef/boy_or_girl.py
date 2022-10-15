s=input()
maparr=dict.fromkeys(s, 0)
for i in range(len(s)):
    maparr[s[i]]+=1
ans=len(maparr)
if ans%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")