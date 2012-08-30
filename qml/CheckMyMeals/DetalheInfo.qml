import QtQuick 1.1
import "cores.js" as Cores

Item {
    id: delegateDetalhe
    width: parent.width; height: childrenRect.height

    property string corBackground: "black"

    BackgroundBase {
        width: parent.width; height: childrenRect.height
        toColor: delegateDetalhe.corBackground

        Row {
            width: parent.width
            z: 1

            Image {
                width: 32; height: 32;
                source: "qrc:///carrinho_compra_neg"
            }

            Column {
                id: col
                width: parent.width

                Text {
                    text: local
                    color: Cores.COR_TEXTO
                    font.pixelSize: 16
                }

                Text {
                    text: " R$" + valor.toFixed(2)
                    color: Cores.COR_TEXTO
                }
            }
        }

        Image {
            width: 32; height: 32
            source: "qrc:///campeao_neg"
            visible: id == cartaoModel.InfoCartao(numero).estudos.maiorCompra.id
            anchors { right: parent.right; verticalCenter: parent.verticalCenter }
            z: 1
        }
    }
}
