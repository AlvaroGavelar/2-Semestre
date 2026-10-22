// Exercício 04: implemente a visualização e a validação da senha aqui.
const mostrarSenha = document.getElementById("mostrarSenha");
const senha = document.getElementById("senha");

mostrarSenha.addEventListener("click", function(e){
    if(senha.type === "password"){
        senha.type = "text";
        confirmarSenha.type = "text";
        mostrarSenha.textContent = "Ocultar";
    }
    else{
        senha.type = "password";
        confirmarSenha.type = "password";
        mostrarSenha.textContent = "Mostrar";
    }
});

const confirmarSenha = document.getElementById("confirmarSenha");
const forcaSenha = document.getElementById("forcaSenha");
const barra = document.getElementById("barraForca");

senha.addEventListener("input", function(e){
    if(senha.value.length === 0){
        forcaSenha.textContent = "Digite uma senha para começar.";
        barra.classList.remove("fraca", "media", "forte");
    }
    if(senha.value.length > 0 && senha.value.length < 6){
        forcaSenha.textContent = "Senha Fraca.";
        barra.classList.remove("media", "forte");
        barra.classList.add("fraca");
    }
    if(senha.value.length >= 6 && senha.value.length <= 9){
        forcaSenha.textContent = "Senha Media.";
        barra.classList.remove("fraca", "forte");
        barra.classList.add("media");
    }
    if(senha.value.length >= 10){
        forcaSenha.textContent = "Senha Forte.";
        barra.classList.remove("media", "fraca");
        barra.classList.add("forte");
    }
});

const confirma = document.getElementById("mensagemConfirmacao");

function verificarSenhas(){

    if(senha.value.length === 0 || confirmarSenha.value.length === 0){
        confirma.textContent = "As senhas ainda não foram verificadas.";
    }

    if(senha.value.length > 1 && confirmarSenha.value.length > 1 && senha.value != confirmarSenha.value){
        confirma.textContent = "Senhas Diferentes";
    }

    if(senha.value.length > 1 && confirmarSenha.value.length > 1 && senha.value === confirmarSenha.value){
        confirma.textContent = "Senhas Iguais";
    }
};

confirmarSenha.addEventListener("input", verificarSenhas);
senha.addEventListener("input", verificarSenhas);

const btn = document.getElementById("criarConta");
const resultado = document.getElementById("resultadoConta");

btn.addEventListener("click", function(e) {
    if (senha.value.length === 0 || confirmarSenha.value.length === 0) {
        resultado.textContent = "Preencha os dois campos de senha!";
    }
    else if (senha.value === confirmarSenha.value) {
        resultado.textContent = "Cadastro com Sucesso!";
    }
    else {
        resultado.textContent = "Cadastro não realizado! Senhas diferentes!";
    }
});