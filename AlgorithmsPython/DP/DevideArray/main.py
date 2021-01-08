#https://codeforces.com/group/FLVn1Sc504/contest/274518/problem/L

def replaceIndex(arr,t,key):
    left,right,a=0,len(t),0
    while(right-left>0):
        a=(left+right)/2
        if t[a]>=key:
            right=a
        else:
            left=a

    return left

def LIS(arr):
    t=[0]*len(arr)
    answer=1
    t[0]=arr[0]

    for i in range(1,len(arr),1):
        if t[0]>arr[i]:
            t[0]=arr[i]
        elif arr[i]>t[answer-1]:
            t[answer]=arr[i]
            answer+=1
        else:
            t[replaceIndex(arr,t,arr[i])]=arr[i]

    return answer

if __name__=="__main__":
    n=int(input())
    arr=[int(input()) for i in range(n)]
    a=arr[::-1]
    
    print(LIS(a))
