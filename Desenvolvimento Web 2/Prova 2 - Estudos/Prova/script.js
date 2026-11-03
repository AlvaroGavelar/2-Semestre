const btn = document.getElementById("btn");
const legenda_grafico = document.getElementById("legendaG");
const legenda = document.getElementById("legenda");
const valorG = document.getElementById("valorG");
const progresso = document.getElementById("progresso")
const valor = document.getElementById("valor");
const numero = document.getElementById("numero");
const largura = document.getElementById("largura");
const barra = document.getElementById("barra");
const bordaA = document.getElementById("arredondado");
const espessura = document.getElementById("espessura");
const cor_borda = document.getElementById("borda");
const cor_fundo = document.getElementById("fundo");
const cor_barra = document.getElementById("corBarra");
const sombra_sim = document.getElementById("sim");
const sombra_nao = document.getElementById("nao");


btn.addEventListener("click", function(e){

    //Legenda
    legenda_grafico.textContent = legenda.value;

    //Valor Grafico
    progresso.style.width = valor.value + "%";
    valorG.textContent = valor.value + "%";

    //Exibir Valor Numerico
    if(!numero.checked){
        valorG.textContent = "";
    }

    //Largura do Grafico
    barra.style.width = largura.value + "px";

    //Borda Arredondada
    if(bordaA.checked){
        barra.style.borderRadius = "20px";
        progresso.style.borderRadius = "20px";
    }
    else{
        barra.style.borderRadius = "0px";
        progresso.style.borderRadius = "0px";
    }

    //Espessura da Borda
    barra.style.borderWidth = espessura.value;

    //Cor da Borda
    barra.style.borderColor = cor_borda.value;

    //Cor Fundo
    barra.style.backgroundColor = cor_fundo.value;

    //Cor Barra
    progresso.style.backgroundColor = cor_barra.value;

    if(sombra_sim.checked){
        barra.style.boxShadow = "4px 4px 2px #bbb";
    }

    if(sombra_nao.checked){
        barra.style.boxShadow = "none"
    }
});