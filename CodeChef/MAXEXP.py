#https://www.codechef.com/submit/MAXEXP
#taking number of test cases
t=int(input())
for i in range(t):
    #taking first line of input: n
    n=int(input())
    #taking the string of length n as input
    s=input()
    #counting the instances of '-'
    mini=s.count('-')
    #counting the instances of '+'
    add=s.count('+')
    #deleting the characters of '-' and '+' from the string
    s=s.replace('+', '')
    s=s.replace('-', '')
    #sorting the string in ascending order
    s=sorted(s)
    #creating a new array
    arr=[]
    #adding the 1st element to the array, which is the first element of the sorted string
    arr.append(s[0])
    for i in range(1, len(s)):
        #while the count of '-' is not 0, keep adding it to the string after 1 element
        if mini!=0:
            arr.append('-')
            mini-=1
        #else, while the count of '+' is not 0, keep adding it to the string after 1 element
        elif add!=0:
            arr.append('+')
            add-=1
        #add element
        arr.append(s[i])
    #convert array to string
    arr=''.join(reversed(arr))
    print(arr)