import QtQuick 1.1
import "cores.js" as Cores

Item {
    id: delegateDetalhe
    width: parent.width; height: col.height

    Row {
        width: parent.width
        z: 1

        Image {
            width: 32; height: 32;
            source: "qrc:///carrinho_compra"
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
                text: Qt.formatDate(dataCompra, "dd/MM/yyyy") + " R$" + valor.toFixed(2)
                color: Cores.COR_TEXTO
            }

            Rectangle {
                width: parent.width; height: 1;
                color: "black"
            }
        }
    }

    Image {
        width: 32; height: 32
        source: "qrc:///campeao"
        visible: id == cartaoModel.InfoCartao(numero).estudos.maiorCompra.id
        anchors { right: parent.right; verticalCenter: parent.verticalCenter }
        z: 1
    }

    Rectangle {
        anchors.fill: parent
        color: (index % 2 === 0 ? Cores.COR_FUNDO : Cores.COR_FUNDO_LISTA)
    }

}
