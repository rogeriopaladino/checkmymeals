import QtQuick 1.1
import "cores.js" as Cores

Row {
    width: parent.width; height: (img.height > txt.height ? img.height : txt.height)

    property alias icone: img.source
    property alias texto: txt.text

    Image {
        id: img
        width: 32; height: 32
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        id: txt
        width: parent.width - img.width
        color: Cores.COR_TEXTO
        smooth: true
        wrapMode: Text.WordWrap
        anchors.verticalCenter: parent.verticalCenter
    }
}
