import requests

# resposta = requests.get("https://api.github.com")
# print(resposta.status_code)
# print(resposta.text)

# dados = {
#     "nome": "Alvaro",
#     "idade": 21
# }

# resposta = requests.post(
#     "https://httpbin.org/post",
#     json=dados
# )

# print(resposta.status_code)

resposta = requests.get("https://jsonplaceholder.typicode.com/users/1")
if resposta.status_code == 200:
    dados = resposta.json()
    print(dados["name"])
    print(dados["email"])
    print(dados["address"]["city"])
else:
    print("Erro na Requisição:", resposta.status_code)