// Exercício 02: implemente o comportamento dos controles.
const cor = document.getElementById("corProduto");
const corF = document.getElementById("corPreview");

cor.addEventListener("change", function(e){
    corF.textContent = cor.value;
});

const aumentar = document.getElementById("aumentar");
const dimunuir = document.getElementById("diminuir");
const quant = document.getElementById("quantidadePreview");
const quantResumo = document.getElementById("quantidadeResumo");
dimunuir.hidden = Number(quant.textContent) <= 1;
const totalPreview = document.getElementById("totalPreview");

aumentar.addEventListener("click", function(e){
    let numero = parseInt(quant.textContent);
    numero++;
    
    if(numero > 1)
        dimunuir.hidden = false;

    quant.textContent = numero.toString();
    quantResumo.textContent = quant.textContent;

    let valor = numero * 59.90;

    totalPreview.textContent = valor.toLocaleString("pt-BR", {
            style: "currency",
            currency: "BRL"
        });
});

dimunuir.addEventListener("click", function(e){
    let numero = parseInt(quant.textContent);

    dimunuir.hidden = numero <= 1;

    if(numero > 1){
        numero--;
        quant.textContent = numero.toString();
        quantResumo.textContent = quant.textContent;
            let valor = numero * 59.90;
            totalPreview.textContent = valor.toLocaleString("pt-BR", {
            style: "currency",
            currency: "BRL"
        });
    }
});

const finalizar = document.getElementById("finalizar");
const msg = document.getElementById("mensagemPedido");

finalizar.addEventListener("click", function(e){
    msg.textContent = "Pedido Concluído! Quantidade: "
        + quantResumo.textContent
        + " | Cor: " + corF.textContent
        + " | Total: " + totalPreview.textContent;
})



    
    
