'''kruskal's by fast union find for weighted undirected graphs
union by rank - O(logn), find - Path Compression - O(logn)  <two techniques complement each other> 
'''
class Graph:
    def __init__(self,num_v):
        self.num_of_vertices = num_v
        self.edges = []
    def addEdge(self,edge):
        self.edges.append(edge)

    '''
    Let the subset {0, 1, .. 9} be represented as below and find() is called
for element 3.
              9
         /    |    \  
        4     5      6
     /     \        /  \
    0        3     7    8
            /  \
           1    2  

When find() is called for 3, we traverse up and find 9 as representative
of this subset. With path compression, we also make 3 as the child of 9 so 
that when find() is called next time for 1, 2 or 3, the path to root is reduced.

               9
         /    /  \    \
        4    5    6     3 
     /           /  \   /  \
    0           7    8  1   2   
    
    
    '''

    def find(self,parents,node):
        if parents[node] != node:
            parents [node] = self.find(parents,parents[node])
        return parents[node]
    def fastunion(self,parents,ranks,n1,n2):
        '''get the parents of both nodes to union them'''
        node1 = self.find(parents,n1)
        node2 = self.find(parents,n2)
        '''get the ranks of parents of both nodes to compare them'''
        if ranks[node1] == ranks[node2]:
            parents[node1] = node2
            ranks[node2]+=1
        elif ranks[node1] > ranks[node2]:
            parents[node2] = node1
            ranks[node1]+=1
        else:
            parents[node1] = node2
            ranks[node2]+=1
    def kruskal(self):
        self.edges = sorted(self.edges,key=lambda x:x[2])
        i = 1
        e = 0
        parents = [i for i in range(self.num_of_vertices)]
        ranks = [1 for _ in range(self.num_of_vertices)]
        while i<self.num_of_vertices:
            edge = self.edges[e] 
            e+=1
            '''get the parents of both nodes to union them'''
            p1 = self.find(parents,edge[0])
            p2 = self.find(parents,edge[1])
            '''print as favourable only if cycle is not formed - i.e not same parents'''
            if  p1!= p2:
                self.fastunion(parents,ranks,edge[0],edge[1])
                i+=1
                print(edge[0],"-->",edge[1],": size - ",edge[2])
#inputs
g = Graph(4) 
g.addEdge([0, 1, 10]) 
g.addEdge([0, 2, 6]) 
g.addEdge([0, 3, 5]) 
g.addEdge([1, 3, 15]) 
g.addEdge([2, 3, 4])
g.kruskal()