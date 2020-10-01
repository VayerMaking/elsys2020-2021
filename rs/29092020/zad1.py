def summerize(x):
    result = 0
    for i in x:
        result = i + result
    return result


print(summerize([1,2,3,4,5]))
