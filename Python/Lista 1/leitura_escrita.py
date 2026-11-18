## W - Escreve e substitui

arquivo = open("dados.text", "w")
arquivo.write("Olá, mundo!")
arquivo.close()

print()

arquivo = open("dados.text", "w")
arquivo.write("Alvaro\n")
arquivo.write("21 anos\n")
arquivo.write("Sistemas de Informação\n")
arquivo.close()

print()

## R - Lê o arquivo
arquivo = open("dados.text", "r")
conteudo = arquivo.read()
print(conteudo)
arquivo.close()

print()

## Readline - Lê linha por linha
arquivo = open("dados.text", "r")
linha1 = arquivo.readline()
linha2 = arquivo.readline()

print(linha1)
print(linha2)
arquivo.close()

print()

## Readlines - Lê todas as linhas
arquivo = open("dados.text", "r")
linhas = arquivo.readlines()
print(linhas)
arquivo.close()

print()

## A - Adiciona no fim
arquivo = open("dados.text", "a")
arquivo.write("Python")
arquivo.close

## With
with open("dados.text", "r") as arquivo:
    conteudo = arquivo.read()
    print(conteudo)


print()

## Exercicio 1
arquivo = open("alunos.text", "w")
arquivo.write("Álvaro")
arquivo.close()

with open("alunos.text", "r") as arquivo:
    print(arquivo.read())

print()

with open("alunos.text", "a") as arquivo:
    arquivo.write("\n2° Semestre")
    arquivo.write("\nDesenvolvimento Web II")

with open("alunos.text", "r") as arquivo:
    conteudo = arquivo.read()
    print(conteudo)