from datetime import datetime, date, timedelta
import time

agora = datetime.now()

print()

print(agora)
print(agora.year)
print(agora.month)
print(agora.day)
print(agora.hour)
print(agora.minute)
print(agora.second)

print()

hoje = date.today()
print(hoje)
print(hoje.year)
print(hoje.month)
print(hoje.day)

print()

nascimento = date(2005, 7, 15)
print(nascimento)

print()

agora = datetime.now()
data_formatada = agora.strftime("%d/%m/%Y %H:%M:%S")
print(data_formatada)

print()

data_texto = "18/11/2006"
data = datetime.strptime(data_texto, "%d/%m/%Y")
print(data)

print()

hoje = date.today()
futuro = hoje + timedelta(days=10)
print(futuro)

print()

hoje = date.today()
futuro = hoje - timedelta(days=10)
print(futuro)

## Exercicio 1
print("Exercicio 1")
hoje = date.today()
hr_hoje = datetime.now()
formatado = datetime.strftime(hoje, "%d/%m/%Y")
formatado_hr = datetime.strftime(hr_hoje, "%H:%M:%S")
print(formatado, formatado_hr)

print()

print("Exercicio 2")
aniversario = input("data de nascimento no formato DD/MM/AAAA:\n")
aniversario = datetime.strptime(aniversario, "%d/%m/%Y").date()
agora = date.today()
tempo = agora - aniversario
print(tempo.days,"dias")

print()

print("Exercicio 3")
segundo = int(input("Quantidade de Segundos:"))
while segundo != 0:
    print(segundo)
    segundo -= 1
    time.sleep(1)

print("Tempo esgotado")
