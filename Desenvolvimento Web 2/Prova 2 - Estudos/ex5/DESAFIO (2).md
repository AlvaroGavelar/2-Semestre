# Exercício 05 — Calculadora de média

## Objetivos
1. Ao enviar `formNotas`, impedir o recarregamento da página.
2. Ler as três notas e convertê-las para números.
3. Verificar se todas foram preenchidas e se estão entre 0 e 100. Se houver erro, mostrar uma mensagem em `erroNotas` e não calcular.
4. Calcular a média aritmética das três notas e exibi-la em `mediaPreview` com uma casa decimal.
5. Se a média for maior ou igual a 60, mostrar `Aprovado` e uma mensagem positiva. Caso contrário, mostrar `Recuperação`.
6. Atualizar a largura de `progressoMedia` de acordo com a média (por exemplo, média 75 deve ocupar 75% da barra).
7. Aplicar a classe `aprovado` ou `recuperacao` em `resultadoCard`, removendo a classe do resultado anterior.

## Dicas
- O formulário usa evento `submit`.
- Para converter texto numérico: `Number(campo.value)`.
- A média de três notas é a soma dividida por 3.
- Para uma casa decimal, veja `toFixed(1)`.
- Use condições `if/else` para decidir a situação.

**Extra:** adicione uma regra de validação: se qualquer nota estiver vazia, não aceite o cálculo, mesmo que `Number("")` resulte em zero.
