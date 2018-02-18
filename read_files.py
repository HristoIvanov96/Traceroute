from sys import argv

if len(argv) > 2:

	file = open(argv[1],'r')
	output = open(argv[2],'w')

	arr = []

	for line in file:
		line = line.split(' ')
		if '*\n' not in line and "traceroute" not in line and len(line)>2:
			arr.append(line[-4])

	for i in range(len(arr) - 1):
		if arr[i+1] != "130.209.240.48" and arr[i+1] != "2001:630:40:f00:e22f:6dff:fe2c:ed80":
			output.write('"' + arr[i] + '"'" -- "'"' + arr[i+1] + '"' + "\n")

	file.close()
	output.close()



		