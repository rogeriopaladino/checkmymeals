.pragma library

var cartaoMainSelecionado = "";
var mensagens = [];
var screenWidth = 0;
var screenHeight = 0;

function formatNumeroCartao(numero)
{
    return  numero.substring(0, 4) + "-" +
            numero.substring(4, 8) + "-" +
            numero.substring(8, 12) + "-" +
            numero.substring(12);
}

function PushNaPilha(pageStack, component) {
    if (pageStack !== null) {
        if (!pageStack.busy)
            pageStack.push(component);
    }
}
