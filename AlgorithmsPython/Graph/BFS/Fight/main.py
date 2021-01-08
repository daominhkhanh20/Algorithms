import sys

def bfs(x,y,n,edge):
	dist=[sys.maxsize]*n
	dist[x]=0
	temp=[x]
	pre=[-1]*n
	pre[x]=x
	while len(temp)!=0:
		u=int(temp.pop(0))
		for i in edge[u]:
			if dist[i]>dist[u]+1:
				dist[i]=dist[u]+1
				temp.append(i)
				pre[i]=u

	print(dist[y]+1)
	pre_y=pre[y]
	path=[y,pre_y]
	while pre_y!=x:
		pre_y=pre[pre_y]
		path.append(pre_y)

	path.append(x)
	path.reverse()
	for i in path:
		print(i,end=" ")
	


if __name__=="__main__":
	n,m,t,c=map(int,input().split())
	edge=[[] for i in range(n+1)]
	for i in range(m):
		u,v=map(int,input().split())
		edge[u-1].append(v-1)
		edge[v-1].append(u-1)
		print(edge)
	print(edge)
	x,y=map(int,input().split())
	bfs(x-1,y-1,n,edge)

