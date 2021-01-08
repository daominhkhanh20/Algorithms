#https: // www.hackerearth.com/fr/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/anupam-graph/

def dfs(g,u,v):
    edge=[]
    for i in range(len(g)):
        edge.append(0)
    s=[u]
    while s:
        temp=s.pop()
        if temp==v:
            break
        edge[temp]=1
        for i in g[temp]:
            if edge[i]==0:
                s+=[i]
    
    s=[v]
    ans=0
    while s:
        ans+=1
        c=s.pop()
        edge[c]=1
        for i in g[c]:
            if edge[i]==0:
                s+=[i]

    return ans



if __name__=="__main__":
    arr=list(map(int,input().split()))
    n,u,v=arr[0],arr[1],arr[2]
    g=[[] for i in range(n+1)]
    for i in range(n-1):
        x,y=map(int,input().split())
        g[x].append(y)
        g[y].append(x)

    d1=dfs(g,u,v)
    d2=dfs(g,v,u)
    print(n*n-n-d1*d2)