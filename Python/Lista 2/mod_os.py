import os

## Pasta Atual
print(os.getcwd())

## Lista Arquivos e pastas
arquivos = os.listdir()
print(arquivos)

## Cria pasta
# os.mkdir("Pasta Teste")

## Verifica se algo existe
if os.path.exists("cadastro.json"):
    print("Achou")
else:
    print("Errouuu")

## Exclui um arquivo
# os.remove("cadastro.json")

# print(os.getcwd())
# arquivos = os.listdir()
# print(arquivos)
# if os.path.exists("cadastro.json"):
#     print("Achou")
# else:
#     print("Errouuu")


if os.path.exists("EstudosPython"):
    print("Já Existe")
elif os.path.exists("PythonFDS"):
    print("já Existe")
else:
    os.mkdir("EstudosPython")
    os.rename("EstudosPython", "PythonFDS")
    print("Operação concluida")

