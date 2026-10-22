# Exercício 02 — Monte seu pedido

O preço unitário é R$ 59,90.

## Objetivos
1. Ao clicar em `aumentar`, acrescentar 1 à quantidade.
2. Ao clicar em `diminuir`, reduzir 1, mas nunca deixar a quantidade menor que 1.
3. Atualizar `quantidadePreview` e `quantidadeResumo` sempre que a quantidade mudar.
4. Ao escolher outra cor, atualizar `corPreview`.
5. Atualizar `totalPreview` com quantidade × 59,90, exibindo duas casas decimais no padrão brasileiro.
6. Ao clicar em `finalizar`, exibir uma mensagem em `mensagemPedido` confirmando quantidade, cor e total.

## Dicas
- Botões: evento `click`.
- Select: evento `change`.
- Converta valores para número quando necessário.
- Para formatar dinheiro, pesquise `toLocaleString("pt-BR", { style: "currency", currency: "BRL" })`.

**Extra:** desabilite o botão de diminuir quando a quantidade chegar a 1.
