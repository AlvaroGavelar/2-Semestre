import sys

## Versão do python
print(sys.version)

## Sistema operacional
print(sys.platform)

## Encerra o programa
idade = 15

if idade < 18:
    print("Acesso Negado")
    sys.exit()

print("Acesso Permitido")

## Recebe argumentos pelo terminal 
print(sys.argv)



print("Versão do Python:", sys.version)
print("Sistema:", sys.platform)
print(sys.argv)

idade = int(sys.argv[2])
nome = sys.argv[1]

if idade < 18:
    print("Acesso Negado")
    sys.exit()

print("Bem Vindo,", nome)