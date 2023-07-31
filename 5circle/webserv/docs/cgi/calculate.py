import sys

def printResult(display, value) :
    fin = open('./docs/fusion_web/calculator.html', 'r')
    for line in fin :
        if (line.find('name="display"') > 0) :
            line = line.replace('name="display"', 'name="display" value="' + str(display) + '"')
        elif (line.find('name="result"') > 0) :
            line = line.replace('name="result"', 'name="result" value="' + str(value) + '"')
        print(line, end="")
    fin.close()

display = sys.argv[1]

try :
    result = eval(display)
    printResult(display, result)
except :
    pass