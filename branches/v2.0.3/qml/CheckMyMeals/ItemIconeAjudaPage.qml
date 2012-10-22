import QtQuick 1.1
import "cores.js" as Cores

Row {
    id: root
    width: parent.width
    spacing: 10

    property alias srcImagem: img.source
    property alias texto: txt.texto
    property bool mostrarFundoNoIcone: false

    Rectangle {
        width: img.width; height: img.height;
        color: (mostrarFundoNoIcone ? "black" : "transparent")

        Image {
            id: img
            width: 32; height: 32
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    ItemTextoAjudaPage {
        id: txt
        width: parent.width - img.width - root.spacing
        anchors.verticalCenter: parent.verticalCenter
    }
}
