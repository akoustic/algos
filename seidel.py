import numpy as np
from numpy.matrixlib.defmatrix import matrix
def apd(A, n: int):
    """Compute the shortest-paths lengths."""
    flag=0
    for i in range(n):
        for j in range(n):
            if i != j:
                if(A[i][j]==0):
                    flag=1
                    break
        if flag==1:
            break
    if flag==0:
        return A       
    Z = np.dot(A,A)
    B = A
    for i in range(n):
        for j in range(n):
            if((i!=j)and(A[i][j] == 1 or Z[i][j] > 0)):
                B[i][j]=1
            else: B[i][j]=0
    T = apd(B, n)
    X = np.dot(T,A)
    degree = [sum(A[i][j] for j in range(n)) for i in range(n)]
    D=T
    for i in range(n):
        for j in range(n):
            if X[i][j] >= T[i][j] * degree[j]:
                D[i][j]=2*T[i][j]
            else: D[i][j]=2 * T[i][j] - 1
    
    return D

# Driver Code 
graph = [[0, 7, 0, 0,0,0,3],
        [7, 0, 6, 0,0,5,4],
        [0, 6, 0, 5,0,1,0],
        [0, 0, 5, 0,3,2,0],
        [0, 0, 0, 3,0,4,0],
        [0, 5, 1, 2,4,0,1],
        [3, 4, 0, 0,0,1,0]]
n=7
res = apd(graph,n) 
print(res)
'''for i in range(n):
    for j in range(n):
        print(res[i][j])'''