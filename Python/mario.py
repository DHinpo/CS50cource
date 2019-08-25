# реалізація get_int 
while True:
	try:
		n = int(input('Height: '))
	except ValueError:
		pass
	else:	
		if n > 0 and n < 9:
			break

# сам print
for i in range(n):
	print(" " * (n-1), end="")
	print("#" * (i+1), end="") # друкує '#' без вирівнювання
	print("  ", end="")
	print("#" * (i+1)) # друкує '#' без вирівнювання

	n-=1
