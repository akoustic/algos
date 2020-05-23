n,k=map(int,input("Enter n and k ").split())
count=0


def binomialcoeff(n,k):
    global count
    C=[[0 for j in range(k+1)] for i in range(n+1)]
    for i in range(n+1):
        for j in range(min(i,k)+1):
            #base cases
            if j==0 or j==i:
                count+=1
                C[i][j]=1
            #recurrence
            else:
                C[i][j]=C[i-1][j-1]+C[i-1][j]
    return C[n][k]

print(binomialcoeff(n,k))
#print number of times base case is executed - 2*(k+1) [n+1+k+1-(n-k)]
print(count)
