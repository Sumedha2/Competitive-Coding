#taking test cases
t=int(input())
for i in range(t):
    #taking input n- the length of the permutation p
    n=int(input())
    #since we cannot form any such permutations with numbers less than 3, we print -1
    if n<=3:
        print(-1)
    #4 is a corner case
    elif n==4:
        print('2 4 1 3')
    else:
        #creating array of 1st half numbers
        arr1=[]
        #creating array of 2nd half numbers
        arr2=[]
        #creating final array
        arr=[]
        #appending the 1st array with numbers starting from 1 to 1st half of n
        for i in range(1, (n//2)+1):
            arr1.append(i)
        #appending the 2nd array with numbers starting from 1st half to 2nd half of n
        for i in range((n//2)+1, n+1):
            arr2.append(i)
        #appending the final array with simultaneous elements from 1st and 2nd arrays respectively
        for i in range(n//2):
            arr.append(arr1[i])
            arr.append(arr2[i])
        #now if the number is odd, we will need to add the last digit separately as the above loop doesn't cover it
        if (n%2==1):
            #we will insert the last element at the 3rd position, otherwise the corner case of 5 will not be covered
            arr.insert(2, arr2[-1])
        #converting the final array to string
        str(arr).strip().split(',')
        #printing elements of the final array 
        print(*arr,sep=' ')
        