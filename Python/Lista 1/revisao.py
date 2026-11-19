import random
import time
from datetime import datetime, date, timedelta
from functools import reduce

# Sorteie 3 alunos aleatoriamente, sem repetir posições.
# Mostre os alunos sorteados.
# Registre o horário em que o sorteio começou.
# Espere 2 segundos entre o início e o fim do sorteio.
# # Mostre quanto tempo a operação demorou.

print("Exercicio 1")
alunos = ["Ana", "Carlos", "João", "Mariana", "Pedro", "Lucas"]

inicio = datetime.now()
sorteado = random.sample(alunos, 3)

print("\nIniciando\n")

# time.sleep(2)

print("\nFinalizado sorteio\n")

print(sorteado)
fim = datetime.now()
duracao = fim - inicio
print("Duração:", duracao.total_seconds(), "segundos")

## Exercicio 2
# Utilize filter() para selecionar somente os números pares.
# Transforme o resultado em uma lista.
# Utilize random.choice() para sortear um dos números pares.
# Mostre a lista dos pares e o número sorteado.
print("\nExercicio 2")
numeros = [12, 5, 8, 21, 30, 7, 14, 3, 18]
lista = list(filter(lambda x: x % 2 == 0, numeros))
sorteio = random.choice(lista)
print(lista)
print(sorteio)

## Exercicio 3
# Utilize zip() para combinar os produtos com seus preços.
# Utilize map() para aplicar um desconto de 10% em cada preço.
# Utilize reduce() para calcular o valor total dos produtos com desconto.
# Mostre os produtos e seus respectivos preços com desconto.
# Mostre o valor total.
print("\nExercicio 3")
produtos = ["Mouse", "Teclado", "Monitor"]
precos = [150, 250, 1200]
nome = list(zip(produtos, precos))
preco_com_desconto = list(map(lambda x: (x[0], x[1] * 0.9), nome))
valor_total = reduce(lambda x, y: x + y[1],preco_com_desconto, 0)
print(preco_com_desconto)
print("Valor total:", valor_total, "R$")