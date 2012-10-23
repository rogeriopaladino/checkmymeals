// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "cores.js" as Cores
import "main.js" as MainScript

Rectangle {
    color: Cores.COR_FUNDO

    Row {
        width: colCartao.width + imgCartao.width
        anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter }

        Image {
            id: imgCartao
            source: "qrc:///card"
        }

        Column {
            id: colCartao

            Text {
                text: MainScript.formatNumeroCartao(numero)
                color: Cores.COR_TEXTO
                smooth: true
                font.pixelSize: 26
            }
            Text {
                width: parent.width
                text:"<i>"+descricao+"</i>"
                color: Cores.COR_TEXTO
                smooth: true
                wrapMode: Text.WordWrap
                font.pixelSize: 20
            }
        }
    }

}
