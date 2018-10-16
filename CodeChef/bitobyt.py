T = int(input())

while(T > 0):
	n = int(input())
	mul_factor = 2**int(n/26)
	bit = 0 
	nibble = 0
	byte = 0
	if((n%26)-1 >= 0 and (n%26)-1 < 2):
		bit = mul_factor
	elif((n%26)-1 >= 2 and (n%26) <= 10):
		nibble = mul_factor
	elif((n%26)-1 >= 10 and (n%26) <= 26):
		byte = mul_factor
	elif(n%26 == 0):
		byte = int(mul_factor/2)
	print(str(bit) + " " + str(nibble) + " " + str(byte))
	T = T-1