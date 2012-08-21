// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "cores.js" as Cores

BackgroundBase {
    id: root

    signal click()

    property string textoSemClick: "clique aqui"
    property string textoComClick: "clique aqui"
    property string cor: "black"

    onCorChanged: root.toColor = root.cor

    Text {
        id: texto
        anchors { fill: parent; margins: 20 }
        text: root.texto
        color: Cores.COR_TEXTO
        font.pixelSize: 20
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.click();
            texto.text = (texto.text = textoSemClick ? textoComClick : textoComClick)
        }
    }
}
