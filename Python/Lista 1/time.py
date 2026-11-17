import time

## Tempo de espera (segundos)
print("Iniciando programa...")
time.sleep(1)
print("Programa iniciado!")

print()

## Retorna tempo atual
agora = time.time()
print(agora)

inicio = time.time()
time.sleep(3)
fim = time.time()
duracao = fim - inicio
print(duracao)

print()

## Converte timestamp em data e hora legivel
agora = time.time()
print(time.ctime(agora))

## Exercicio
inicio = time.time()
time.sleep(5)
fim = time.time()
duracao = fim - inicio
print(round(duracao, 2))

## Exercicio 2
segundos = int(input("Quantos segundos deseja esperar? "))
inicio = time.time()
print("\nAguardando...")
time.sleep(segundos)
fim = time.time()
duracao = fim - inicio
print(duracao)