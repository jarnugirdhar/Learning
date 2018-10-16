T = int(input())

def digitsum(x):
	sum_val = 0
	while(x > 0):
		sum_val = sum_val+(x%10)
		x = int(x/10)
	return sum_val

while(T > 0):
	n, d = map(int, input().split(" "))
	queue = []
	queue_min = []
	min_val = 0
	min_digit_val = 0
	counter = 0
	i = 1
	if(d == 0):
		while(digitsum(n)/10 > 0):
			min_val = digitsum(n)
			counter += 1
	elif(n == 0 or n == 1):
		min_val = n
		counter = 0
	else:
		queue.append(n)
		temp = digitsum(n)
		min_val = digitsum(n)
		while(int(temp/10) > 0):
			min_val = digitsum(n)
			counter += 1
		queue.append(min(n, min_val))
		queue_min.append(min(queue))
		while(min(queue) >= min(queue_min)):
			n = n+i*d
			counter += 1
			while(digitsum(n)/10 > 0):
				min_digit_val = digitsum(n)
				counter += 1
			queue.append(min(n, min_digit_val))
			queue_min.append(min(queue))
	print(min_val)
	T = T-1