from z3 import * # load z3 library
X=[[[Bool("x_%s_%s_%s" %(i,j,k)) for i in range(9)]for j in range(9)]for k in range (9)]
a=[[[Bool("a_%s_%s_%s" %(i,j,k)) for i in range(9)]for j in range(9)]for k in range (9)]
b=[[[Bool("b_%s_%s_%s" %(i,j,k)) for i in range(9)]for j in range(9)]for k in range (9)]
c=[[[Bool("c_%s_%s_%s" %(i,j,k)) for i in range(9)]for j in range(9)]for k in range (9)]
d=[[[Bool("d_%s_%s_%s" %(i,j,k)) for i in range(9)]for j in range(9)]for k in range (9)]
s=Solver()
#calling solver
for i in range (9):
    elements = list(map(int, input().split()))
    for j in range(9):
        if (elements[j]!=0):
            s.add(X[i][j][elements[j]-1])
#taking input
for i in range(9):
    for j in range(9):
        s.add((X[j][0][i]==a[j][0][i]))
        s.add((X[0][j][i]==b[j][0][i]))
        s.add((X[(j%3)*3][(j//3)*3][i]==c[j][0][i]))
        s.add(X[i][j][0]==d[j][0][i])
        #inialize to implies
        for k in range(9):
            if (k!=0):
                s.add(Or(X[j][k][i],a[j][k-1][i])==a[j][k][i])
                s.add(Or(X[k][j][i],b[j][k-1][i])==b[j][k][i])
                s.add(Or(X[(j%3)*3+k%3][(j//3)*3+k//3][i],c[j][k-1][i])==c[j][k][i])
                s.add(Or(X[i][j][k],d[j][k-1][i])==d[j][k][i])
                #if sum or number reached one before then continue with one
                s.add(Not(And((a[j][k-1][i],(X[j][k][i])))))
                s.add(Not(And((b[j][k-1][i],(X[k][j][i])))))
                s.add(Not(And((c[j][k-1][i],(X[(j%3)*3+k%3][(j//3)*3+k//3][i])))))
                s.add(Not(And((d[j][k-1][i],(X[i][j][k])))))
                # if number and sum both one then wrong
        s.add(a[j][8][i],b[j][8][i],c[j][8][i],d[j][8][i])
print("\n")
if (s.check()==sat):
    m=s.model()
    for i in range(9):
        for j in range(9):
            for k in range(9):
                if (m.evaluate(X[i][j][k])):
                    print(k+1, end=" ")
        print(end="\n")
else:
    print("no solution exists")