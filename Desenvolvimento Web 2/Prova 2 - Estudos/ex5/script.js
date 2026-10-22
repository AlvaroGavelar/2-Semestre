
const formNotas = document.getElementById("formNotas");

const nota1 = document.getElementById("nota1");
const nota2 = document.getElementById("nota2");
const nota3 = document.getElementById("nota3");

const erroNotas = document.getElementById("erroNotas");
const resultadoCard = document.getElementById("resultadoCard");
const mediaPreview = document.getElementById("mediaPreview");
const situacaoPreview = document.getElementById("situacaoPreview");
const mensagemPreview = document.getElementById("mensagemPreview");
const progressoMedia = document.getElementById("progressoMedia");

// Vamos fazer nossa própria validação
formNotas.noValidate = true;

formNotas.addEventListener("submit", function(e) {
    e.preventDefault();
    console.log("Formulário interceptado!");

    erroNotas.textContent = "";

    // Limpa o resultado anterior
    resultadoCard.classList.remove("aprovado", "recuperacao", "estado-inicial");
    mediaPreview.textContent = "—";
    situacaoPreview.textContent = "Aguardando notas";
    mensagemPreview.textContent = "Preencha as três avaliações para ver seu resultado.";
    progressoMedia.style.width = "0%";

    // Verifica se os campos estão vazios
    if (nota1.value === "" || nota2.value === "" || nota3.value === "") {
        erroNotas.textContent = "Preencha as três notas!";
        return;
    }

    // Converte os textos para números
    const n1 = Number(nota1.value);
    const n2 = Number(nota2.value);
    const n3 = Number(nota3.value);

    // Verifica se as notas estão entre 0 e 100
    if (
        n1 < 0 || n1 > 100 ||
        n2 < 0 || n2 > 100 ||
        n3 < 0 || n3 > 100
    ) {
        erroNotas.textContent = "As notas devem estar entre 0 e 100!";
        return;
    }

    // Calcula a média
    const media = (n1 + n2 + n3) / 3;

    mediaPreview.textContent = media.toFixed(1).replace(".", ",");

    // Atualiza a barra de progresso
    progressoMedia.style.width = media + "%";

    // Verifica a situação do aluno
    if (media >= 60) {
        situacaoPreview.textContent = "Aprovado";
        mensagemPreview.textContent = "Parabéns! Você atingiu a média necessária.";
        resultadoCard.classList.add("aprovado");
    } else {
        situacaoPreview.textContent = "Recuperação";
        mensagemPreview.textContent = "Você precisa melhorar sua média.";
        resultadoCard.classList.add("recuperacao");
    }
});
