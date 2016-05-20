#Test case genrator for sorting
#Written by Chaitya Shah

import random
test_case = []
(start,end) = (1,10000) #range for test cases
numberOfTestCase = 200000     #read the variable name
for i in range(numberOfTestCase):
    test_case.append(random.randrange(start,stop=end))

input_file = open("input_file.txt","w")
for i in test_case:
    s = str(i) + " "
    input_file.write(s)

input_file.close()


