import random

## Inteiro entre 1 - 10
# numero = random.randint(1,10)
# print(numero)

print()

## Decimal entre 0 - 1
numero = random.random()
print(numero)

print()

## Decimal entre o intervalo
numero = random.uniform(1,10)
print(numero)

print()

## Sorteio de lista
nomes = ["Alvaro", "Mariana", "Lara"]
sorteado = random.choice(nomes)
print(sorteado)

print()

## Embaralha a lista
numeros = [1, 2, 3, 4, 5]
random.shuffle(numeros)
print(numeros)

print()

## Seleciona uma quantidade de elementos aleatórios sem repetir
numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
sorteados = random.sample(numeros, 8)
print(sorteados)

print()

## Exercicio 1
numeros1 = [random.randint(1,100) for i in range(6)]
print(numeros1)

print()

## Exercicio 2
nomes = ["Alvaro", "Mariana", "Arthur", "Lara", "Pedro"]
sorteado = random.choice(nomes)
print(sorteado)

print()

## Exercicio 3
numeros = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
sorteados = random.sample(numeros, 3)
print(sorteados)

print()

## Exercicio 4
numero = range(1, 61)
sorteados = random.sample(numero, 6)
print(sorteados)