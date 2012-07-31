import QtQuick 1.1
import com.nokia.symbian 1.1
import com.rogerio.model 1.0

import "cores.js" as Cores
import "main.js" as MainScript

Item {
    id: delegateCartao
    width: parent.width; height: childrenRect.height;

    property int quantidadeCartao: 0

    signal click(string numero);
    signal duploClick(string numero);
    signal dedoPressionado(string numero, double x, double y);

    Rectangle {
        anchors.fill: parent
        color: (index % 2 == 0 ? Cores.COR_FUNDO : Cores.COR_FUNDO_LISTA)
    }

    Column {
        id: colRoot
        width: parent.width;
        //z: parent.z + 1

        Row {
            width: parent.width;
            z: parent.z + 1

            Rectangle {
                width: parent.width; height: colCartao.height
                gradient: Gradient {
                    GradientStop {
                        position: 0.00;
                        color: Cores.COR_FUNDO_DEGRADE_P0;
                    }
                    GradientStop {
                        position: 1.00;
                        color: Cores.COR_FUNDO_DEGRADE_P1;
                    }
                }

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
                        }
                    }                    
                }
            }
        }       

        Row {
            width: parent.width

            ItemMainInfoCartao {
                width: parent.width * 0.30
                icone: "qrc:///money"
                texto: "R$ <b>" + saldo.toFixed(2) + "</b>"
            }

            ItemMainInfoCartao {
                width: parent.width * 0.30
                icone: "qrc:///grafico"
                texto: "R$ " + estudos.gastoMedioDiario.toFixed(2)
            }
        }

        ItemMainInfoCartao {
            icone: "qrc:///carrinho_compra"
            visible: estudos.ultimaCompra.local !== ""
            texto: estudos.ultimaCompra.local + " em " + Qt.formatDate(estudos.ultimaCompra.data, "dd/MM/yyyy") + " R$" + estudos.ultimaCompra.valor.toFixed(2)
        }

        ItemMainInfoCartao {
            icone: "qrc:///caiu"
            visible: !isNaN(dataBeneficio)
            texto: "<b>" + (!isNaN(dataBeneficio) ? Qt.formatDate(dataBeneficio, "dd/MM/yyyy") : "--/--/----") + "</b> - R$ <b>" +valorBeneficio.toFixed(2)+ "</b>"
        }

        ItemMainInfoCartao {
            icone: "qrc:///calendario"
            visible: !isNaN(dataProximoBeneficio)
            texto: "<b>" + Qt.formatDate(dataProximoBeneficio, "dd/MM/yyyy") + "</b> - R$ <b> " + valorProximoBeneficio.toFixed(2) + "</b>"
        }

        ItemMainInfoCartao {
            icone: "qrc:///favorito"
            visible: estudos.vezesNoLocalFavorito > 0
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
            icone: "qrc:///campeao"
            texto: makeTexto()
            visible: !isNaN(estudos.maiorCompra.data)
        }

        Rectangle {
            width: parent.width; height: 1
            color: "black"
        }

        Rectangle {
            width: parent.width; height: 20
            visible: delegateCartao.quantidadeCartao != (index + 1)
            z: 1
            gradient: Gradient {
                GradientStop {
                    position: 0.00;
                    color: (index % 2 == 0 ? Cores.COR_FUNDO : Cores.COR_FUNDO_LISTA);
                }
                GradientStop {
                    position: 1.00;
                    color: Cores.COR_FUNDO_DEGRADE_P0;
                }
            }
        }
    }

    ProgressBar {
        width: parent.width * 0.20
        anchors { top: parent.top; topMargin: 5; right: parent.right; rightMargin: 5 }
        maximumValue: valorBeneficio
        value: (valorBeneficio - saldo)
    }

    MouseArea {
        id: mouseArea1
        anchors.fill: parent        

        onClicked: {
            delegateCartao.click(numero);
        }
        onDoubleClicked: {
            delegateCartao.duploClick(numero);
        }
        onPressAndHold: {            
            var x = mouseX + delegateCartao.x
            var y = mouseY + delegateCartao.y

            delegateCartao.dedoPressionado(numero, x, y);
        }
    }
}
