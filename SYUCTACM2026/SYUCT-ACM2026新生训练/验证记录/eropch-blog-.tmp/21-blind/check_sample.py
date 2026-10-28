g=["0101","1010","0010","1101"]
n=len(g); m=len(g[0])
out=[]
for i in range(n):
    row=[]
    for j in range(m):
        c=0
        for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
            ni,nj=i+di,j+dj
            if 0<=ni<n and 0<=nj<m and g[ni][nj]=='1': c+=1
        row.append(str(c))
    out.append(" ".join(row))
print("\n".join(out))
