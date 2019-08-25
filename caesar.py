import sys

def main():
	if len(sys.argv) != 2:
		print('Usage: python caesar.py k')
		sys.exit(1)

	k = int(sys.argv[1])
	text1 = input('plaintext: ')
	print ('ciphertext: ', end = "")
	
	for c in text1:
		t = ord(c)
		if t > 64 and t < 91:
			t = t + k%26
			if t > 90:	
				t = t - 26
		elif t > 96 and t < 123:
			t = t + k%26
			if t > 122:
				t = t - 26
		print (chr(t), end = "")
	print()

if __name__=="__main__":
	main()
