import time
from datetime import datetime, date, timedelta
import random

participantes = ["Mariana", "Lara", "Alvaro", "Arthur", "Maria"]
tempo = 3

print("\n=== SORTEIO DE BRINDES ===\n")
print("\nIniciando sorteio...\n")

inicio = datetime.now()

print("\nAguarde")

while tempo > 0:
    print(tempo)
    tempo -= 1
    time.sleep(1)

sorteado = random.choice(participantes)
fim = datetime.now()
print("\nO vencedor foi", sorteado, "!\n")

print("Sorteio iniciado:", inicio.strftime("%H:%M:%S"))
print("Sorteio finalizado:", fim.strftime("%H:%M:%S"))

duracao = fim - inicio

print("Duração:", duracao.total_seconds(), "segundos")


