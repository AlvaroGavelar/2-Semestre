// Seleção do visor
const quant = document.getElementById("quantidadPreview");

// Variáveis de estado da calculadora
let valorAtual = "0";
let valorAnterior = null;
let operacaoPendente = null;
let novoNumero = true; // Indica se o próximo clique deve limpar o visor antes de digitar

// Função para atualizar o visor
function atualizarVisor() {
    quant.textContent = valorAtual;
}

// Evento para botões numéricos e vírgula
const botoesNumeros = document.querySelectorAll(".btn-num");
botoesNumeros.forEach(botao => {
    botao.addEventListener("click", function() {
        const digito = this.getAttribute("data-valor");

        if (digito === ",") {
            if (novoNumero) {
                valorAtual = "0,";
                novoNumero = false;
            } else if (!valorAtual.includes(",")) {
                valorAtual += ",";
            }
            atualizarVisor();
            return;
        }

        if (novoNumero || valorAtual === "0") {
            valorAtual = digito;
            novoNumero = false;
        } else {
            valorAtual += digito;
        }
        atualizarVisor();
    });
});

// Evento para operadores básicos (+, -, *, /)
const botoesOperadores = document.querySelectorAll(".btn-operador");
botoesOperadores.forEach(botao => {
    botao.addEventListener("click", function() {
        const op = this.getAttribute("data-op");

        if (operacaoPendente !== null && !novoNumero) {
            calcular();
        }

        valorAnterior = parseFloat(valorAtual.replace(",", "."));
        operacaoPendente = op;
        novoNumero = true;
    });
});

// Botão Igual (=)
document.getElementById("igual").addEventListener("click", function() {
    if (operacaoPendente !== null && valorAnterior !== null) {
        calcular();
        operacaoPendente = null;
        valorAnterior = null;
        novoNumero = true;
    }
});

// Função para realizar os cálculos principais
function calcular() {
    const num1 = valorAnterior;
    const num2 = parseFloat(valorAtual.replace(",", "."));
    let resultado = 0;

    switch (operacaoPendente) {
        case "+": resultado = num1 + num2; break;
        case "-": resultado = num1 - num2; break;
        case "*": resultado = num1 * num2; break;
        case "/": 
            resultado = num2 !== 0 ? num1 / num2 : "Erro"; 
            break;
    }

    valorAtual = resultado.toString().replace(".", ",");
    atualizarVisor();
}

// Funções de Limpeza (C e CE)
document.getElementById("c").addEventListener("click", function() {
    valorAtual = "0";
    valorAnterior = null;
    operacaoPendente = null;
    novoNumero = true;
    atualizarVisor();
});

document.getElementById("ce").addEventListener("click", function() {
    valorAtual = "0";
    novoNumero = true;
    atualizarVisor();
});

// Botão Backspace (apagar último caractere)
document.getElementById("backspace").addEventListener("click", function() {
    if (valorAtual.length > 1) {
        valorAtual = valorAtual.slice(0, -1);
    } else {
        valorAtual = "0";
        novoNumero = true;
    }
    atualizarVisor();
});

// Inverter sinal (+/-)
document.getElementById("mais-menos").addEventListener("click", function() {
    let num = parseFloat(valorAtual.replace(",", "."));
    if (num !== 0) {
        num = num * -1;
        valorAtual = num.toString().replace(".", ",");
        atualizarVisor();
    }
});

// Operações científicas simples (1/x, x², √x, %)
document.getElementById("quadrado").addEventListener("click", function() {
    let num = parseFloat(valorAtual.replace(",", "."));
    valorAtual = (num * num).toString().replace(".", ",");
    novoNumero = true;
    atualizarVisor();
});

document.getElementById("raiz").addEventListener("click", function() {
    let num = parseFloat(valorAtual.replace(",", "."));
    if (num >= 0) {
        valorAtual = Math.sqrt(num).toString().replace(".", ",");
    } else {
        valorAtual = "Erro";
    }
    novoNumero = true;
    atualizarVisor();
});

document.getElementById("inverso").addEventListener("click", function() {
    let num = parseFloat(valorAtual.replace(",", "."));
    if (num !== 0) {
        valorAtual = (1 / num).toString().replace(".", ",");
    } else {
        valorAtual = "Erro";
    }
    novoNumero = true;
    atualizarVisor();
});

document.getElementById("porcentagem").addEventListener("click", function() {
    let num = parseFloat(valorAtual.replace(",", "."));
    valorAtual = (num / 100).toString().replace(".", ",");
    novoNumero = true;
    atualizarVisor();
});