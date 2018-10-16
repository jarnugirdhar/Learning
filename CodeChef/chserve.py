T = int(input())

while(T > 0):
	p1, p2, k = map(int, input().split(" "))
	rem = (p1+p2)%k
	if (((p1+p2-rem)/k)%2 == 0):
		print("CHEF")
	else:
		print("COOK")
	T = T-1