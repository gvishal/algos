scc=[]
with open("Output1.txt","r") as f:
	for line in f:
		a,b=line.split()
		scc.append(int(b))
scc.sort(reverse=True)
print scc[0:5]
