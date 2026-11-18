import json

aluno = {
    "nome": "Álvaro",
    "idade": 21,
    "curso": "Sistemas de Informação"
}

## Dump escreve

with open("aluno.json", "w", encoding="utf-8") as arquivo:
    json.dump(aluno, arquivo, indent=4, ensure_ascii=False)

with open("aluno.json", "r", encoding="utf-8") as arquivo:
    dados = json.load(arquivo)

print(dados)


cadastro = {
    "Nome": "Álvaro",
    "Idade": 21,
    "Curso": "Sistemas de Informação",
    "Perido": "Segundo",
    "Disciplinas": [
        "ED",
        "Desenvolvimento Web II",
        "BD1"
    ]
}

with open("cadastro.json", "w", encoding="utf-8") as arquivo:
    json.dump(cadastro, arquivo, ensure_ascii=False)

with open("cadastro.json", "r", encoding="utf-8") as arquivo:
    dados = json.load(arquivo)

print(dados)