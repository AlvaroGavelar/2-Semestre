// Exercício 01: escreva sua solução aqui.
const nome = document.getElementById("nomePerfil")
const nomePreview = document.getElementById("nomePreview");

nome.addEventListener("input", function(e){

    if(nome.value === ""){
        nomePreview.textContent = "Seu Nome";
    }
    else
        nomePreview.textContent = nome.value;
});

const curso = document.getElementById("cursoPerfil");
const cursoPreview = document.getElementById("cursoPreview");

curso.addEventListener("input", function(e){
    cursoPreview.textContent = curso.value;
});

const temaPerfil = document.getElementById("temaPerfil");
const cartaoPerfil = document.getElementById("cartaoPerfil");

temaPerfil.addEventListener("change", function(e){
    if(temaPerfil.value === "azul"){
        cartaoPerfil.classList.remove("tema-verde","tema-roxo");
        cartaoPerfil.classList.add("tema-azul");
    }
    if(temaPerfil.value === "verde"){
    cartaoPerfil.classList.remove("tema-azul","tema-roxo");
    cartaoPerfil.classList.add("tema-verde");
    }
    if(temaPerfil.value === "roxo"){
        cartaoPerfil.classList.remove("tema-verde","tema-azul");
        cartaoPerfil.classList.add("tema-roxo");
    }
})