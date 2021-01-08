from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph=defaultdict(list)

    def add_edge(self,u,v,d_uv):
        self.graph[u].append((v,d_uv))

    def generate_edges(self):
        edges=[]
        for node in self.graph:
            for neighbour in self.graph[node]:
                edges.append((node,neighbour))
        return edges

G=Graph()
G.add_edge(1,2,1)
G.add_edge(1,3,2)
G.add_edge(2,3,9)
G.add_edge(2,4,10)

dic=G.graph
for key,value in dic.items():
    print(value)
