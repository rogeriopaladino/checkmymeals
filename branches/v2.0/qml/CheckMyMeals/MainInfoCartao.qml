import QtQuick 1.1
import com.nokia.symbian 1.1
import com.rogerio.model 1.0

import "cores.js" as Cores
import "main.js" as MainScript

Item {
    id: delegateCartao
    width: parent.width; height: colRoot.height;

    property int quantidadeCartao: 0
    property string corBackground: "black"

    signal click(string numero);
    signal duploClick(string numero);
    signal dedoPressionado(string numero, double x, double y);

    BackgroundBase {
        id: rectMaster
        width: parent.width; height: colRoot.height;
        toColor: delegateCartao.corBackground

        Column {
            id: colRoot
            anchors.centerIn: parent
            width: parent.width;

            Row {
                width: parent.width;

                Rectangle {
                    width: parent.width; height: colCartao.height
                    color: rectMaster.color

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
                    width: parent.width * 0.50
                    icone: "qrc:///money_neg"
                    texto: "R$ <b>" + saldo.toFixed(2) + "</b>"
                }

                ItemMainInfoCartao {
                    width: parent.width * 0.50
                    icone: "qrc:///grafico_neg"
                    texto: "R$ " + estudos.gastoMedioDiario.toFixed(2)
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
