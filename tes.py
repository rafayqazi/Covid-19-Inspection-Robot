def firstFunction():
    var = 100
    print(var)

def secondFunction():
    print(firstFunction.var)

firstFunction()
secondFunction()

print(firstFunction.var)