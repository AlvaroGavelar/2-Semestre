numeros = [2,4,6,8,10]
resultados = map(lambda x: x * 2, numeros)
print(list(resultados))

print()

precos = [54,76,87,98,43,54]
novo_preco = list(map(lambda x: x + 10, precos))
print(novo_preco)

print()

alturas = [34, 65, 76, 65]
nova_altura = list(map(lambda x: x - 10, alturas))
print(nova_altura)

print()

idades = [10, 15, 20, 25, 30]
nova_idade = list(map(lambda x: x + 2, idades))
print(nova_idade)

print()

numero = [3, 5, 7 , 9]
novo_numero = list(map(lambda x: x ** 2, numero))
print(novo_numero)