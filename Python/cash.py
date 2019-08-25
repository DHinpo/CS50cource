# реалізація get_float 
while True:
	try:
		dollars = float(input('Change owed: '))
	except ValueError:
		pass
	else:	
		if dollars > 0:
			break

# підрахунок монет 
coins = round(dollars * 100)
r = 0
if coins >= 25:
    r = r + coins//25
    coins = coins%25
if coins >= 10:
    r = r + coins//10
    coins = coins%10
if coins >= 5:
    r = r + coins//5
    coins = coins%5
r = r + coins
print(r)