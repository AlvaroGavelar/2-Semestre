const nome = document.getElementById("nomeTitular");
const nomeCartao = document.getElementById("titularPreview");

nome.addEventListener("input", function(e){
    nomeCartao.textContent = nome.value.toUpperCase(); 
});


const numero = document.getElementById("numeroCartao");
const numeroCartao = document.getElementById("numeroPreview");

numero.addEventListener("input", function(e){
    let valor = numero.value.replace(/\D/g, "");
    let formatado = "";

    for(let i = 0; i < valor.length; i+=4){
        if(i > 0){
            formatado += " ";
        }

        formatado += valor.slice(i, i + 4);
    } 

    numeroCartao.textContent = formatado;
});

const validadade = document.getElementById("validadeCartao");
const validadadeCartao = document.getElementById("validadePreview");

validadade.addEventListener("input", function(e){
    let vali = validadade.value.replace("/", "");
    let formatado = "";

    formatado += vali.slice(0, 2);

    if (vali.length > 2) {
        formatado += "/" + vali.slice(2, 4);
    }

    validadadeCartao.textContent = formatado;

});

const bandeira = document.getElementById("bandeiraCartao");
const bandeiraPreview = document.getElementById("bandeiraPreview");

bandeira.addEventListener("change", function(e){
    bandeiraPreview.textContent = bandeira.options[bandeira.selectedIndex].text.toUpperCase();
})

const classico = document.getElementById("modeloClassico");
const gold = document.getElementById("modeloGold");
const platinum = document.getElementById("modeloPlatinum");
const opcaoCartao = document.getElementById("cartaoPreview");

classico.addEventListener("click", function(e){
    opcaoCartao.classList.remove("gold", "platinum");
    opcaoCartao.classList.add("classico");
});

gold.addEventListener("click", function(e){
    opcaoCartao.classList.remove("classico", "platinum");
    opcaoCartao.classList.add("gold");
});

platinum.addEventListener("click", function(e){
    opcaoCartao.classList.remove("gold", "classico");
    opcaoCartao.classList.add("platinum");
});

const contactless = document.getElementById("beneficioContactless");
const internacional = document.getElementById("beneficioInternacional");
const cashback = document.getElementById("beneficioCashback");

const tagContactless = document.getElementById("tagContactless");
const tagInternacional = document.getElementById("tagInternacional");
const tagCashback = document.getElementById("tagCashback");

contactless.addEventListener("change", function(e){
    tagContactless.hidden = !contactless.checked;
});

internacional.addEventListener("change", function(e){
    tagInternacional.hidden = !internacional.checked;
});

cashback.addEventListener("change", function(e){
    tagCashback.hidden = !cashback.checked;
});