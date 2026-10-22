# Exercício 04 — Validador de senha

## Objetivos
1. O botão `mostrarSenha` deve alternar o campo `senha` entre os tipos `password` e `text`. O texto do botão deve alternar entre `Mostrar` e `Ocultar`.
2. Conforme a senha for digitada, atualize `forcaSenha` e a largura de `barraForca`:
   - vazia: peça para digitar;
   - menos de 6 caracteres: senha fraca;
   - de 6 a 9 caracteres: senha média;
   - 10 ou mais caracteres: senha forte.
3. Use as classes `fraca`, `media` e `forte` na barra. Limpe a classe antiga antes de aplicar a nova.
4. Conforme os campos mudarem, verifique se `senha` e `confirmarSenha` são iguais. Mostre mensagem apropriada em `mensagemConfirmacao`.
5. Ao clicar em `criarConta`, informe sucesso somente quando os campos estiverem preenchidos e as senhas forem iguais. Caso contrário, explique o que falta em `resultadoConta`.

## Dicas
- Para alternar `type`, use uma condição `if/else`.
- `senha.value.length` informa a quantidade de caracteres.
- Compare os valores dos dois campos.
- Use `classList.remove()` e `classList.add()`.

**Observação:** isto é um exercício de interface; não é um sistema real de segurança de senhas.
