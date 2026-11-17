## Numeros pares
numeros = [2, 6, 7, 9, 3, 10]
novo_numeros = list(filter(lambda x: x % 2 == 0, numeros))
print(novo_numeros)

print()

numeros2 = [10, 15, 20, 25, 30]
novo_numeros2 = list(filter(lambda x: x > 20, numeros2))
print(novo_numeros2)

print()

notas = [4, 7, 9, 5, 10, 6, 3]
nova_notas = list(filter(lambda x: x >= 7, notas))
print(nova_notas)