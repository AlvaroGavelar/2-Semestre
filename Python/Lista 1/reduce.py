from functools import reduce

numeros = [2, 4, 6, 8]
resultado = reduce(lambda x, y: x + y, numeros)
print(resultado)