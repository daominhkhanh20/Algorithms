
#longest subsequense incresing
def LIS(arr,n):
    v=[]
    for i in range(n):
        v.append(0)
    
    v[0]=1
    for i in range(n):
        v[i]=1
        for j in range(i):
            if arr[i]>arr[j] and v[i]<v[j]+1:
                v[i]=v[j]+1
    
    return v

if __name__=="__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    v=LIS(arr,n)
    t=LIS(arr[::-1],n)[::-1]
    
    a=max(2*min(v[i],t[i])-1 for i in range(n))
    print(a)
    
    



