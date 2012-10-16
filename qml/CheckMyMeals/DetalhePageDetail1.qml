// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "main.js" as MainScript
import "cores.js" as Cores

Rectangle {
    color: Cores.COR_FUNDO

    ListView {
        model: cartaoProxy
        anchors.fill: parent
        delegate: Column {
            width: parent.width

            Row {
                width: parent.width

                Image {
                    id: imgCartao
                    source: "qrc:///card"
                }

                Column {
                    id: colCartao
                    width: parent.width
                    Text {
                        text: MainScript.formatNumeroCartao(numero)
                        color: Cores.COR_TEXTO
                        smooth: true
                        font.pixelSize: 20
                    }
                    Text {
                        width: parent.width
                        text:"<i>"+descricao+"</i>"
                        color: Cores.COR_TEXTO
                        smooth: true
                        wrapMode: Text.WordWrap
                        font.pixelSize: 18
                    }
                }
            }

            Row {
                width: parent.width

                ItemMainInfoCartao {
                    width: parent.width / 2
                    icone: "qrc:///money_neg"
                    texto: "R$ <b>" + saldo.toFixed(2) + "</b>"
                }

                ItemMainInfoCartao {
                    width: parent.width / 2
                    icone: "qrc:///grafico_neg"
                    texto: "R$ " + estudos.gastoMedioDiario.toFixed(2)
                }
            }

            ItemMainInfoCartao {
                icone: "qrc:///carrinho_compra_neg"
                visible: estudos.ultimaCompra.local !== ""
                texto: estudos.ultimaCompra.local + " em " + Qt.formatDate(estudos.ultimaCompra.data, "dd/MM/yyyy") + " R$" + estudos.ultimaCompra.valor.toFixed(2)
            }

            ItemMainInfoCartao {
                icone: "qrc:///caiu_neg"
                visible: !isNaN(dataBeneficio) && !util.versaoFree
                texto: "<b>" + (!isNaN(dataBeneficio) ? Qt.formatDate(dataBeneficio, "dd/MM/yyyy") : "--/--/----") + "</b> - R$ <b>" +valorBeneficio.toFixed(2)+ "</b>"
            }

            ItemMainInfoCartao {
                icone: "qrc:///calendario_neg"
                visible: !isNaN(dataProximoBeneficio) && !util.versaoFree
                texto: "<b>" + Qt.formatDate(dataProximoBeneficio, "dd/MM/yyyy") + "</b> - R$ <b> " + valorProximoBeneficio.toFixed(2) + "</b>"
            }

            ItemMainInfoCartao {
                icone: "qrc:///favorito_neg"
                visible: estudos.vezesNoLocalFavorito > 0 && !util.versaoFree
                texto: estudos.localFavorito + " ("+estudos.vezesNoLocalFavorito+" visita"+ (estudos.vezesNoLocalFavorito > 1 ? "s" : "")+" - R$"+ estudos.valorNoLocalFavorito.toFixed(2) +")"
            }

            ItemMainInfoCartao {
                function makeTexto() {
                    var local = estudos.maiorCompra.local;
                    var data = estudos.maiorCompra.data;
                    var valor = estudos.maiorCompra.valor;
                    var texto = "";
                    texto = local + " em " + Qt.formatDate(data, "dd/MM/yyyy") + " R$" + valor.toFixed(2);
                    return texto;
                }
                icone: "qrc:///campeao_neg"
                texto: makeTexto()
                visible: !isNaN(estudos.maiorCompra.data) && !util.versaoFree
            }

            ItemTextoAjudaPage {
                visible: util.versaoFree
                texto: "Mais informações estão disponíveis na versão completa! Adquira a sua através da loja!"
            }
        }
    }
}
