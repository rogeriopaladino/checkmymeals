// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root
    width: parent.width
    height: childrenRect.height

    property string textoInfo: ""
    property string textoDescricao: ""
    property int margemEsquerda: 15
    property int tamanhoFonteTitulo: 22
    property int tamanhoFonteDescricao: 18

    signal exibido()

    function iniciar() {
        meuTimer.start();
    }

    function resetar() {

    }

    Text {
        id: txtInfo
        color: platformStyle.colorNormalLink
        text: root.textoInfo
        font { pixelSize: tamanhoFonteTitulo; italic: true }
        x: -parent.width
    }

    Rectangle {
        id: separador
        width: parent.width * 0.65; height: 1
        color: platformStyle.colorNormalLink
        x: txtInfo.x; y: txtInfo.y + txtInfo.height + 10
    }

    Text {
        id: txtDescricao
        width: parent.width - root.margemEsquerda
        color: platformStyle.colorNormalLight
        text: root.textoDescricao
        font { pixelSize: tamanhoFonteDescricao }
        x: txtInfo.x; y: separador.y + separador.height + 1
        wrapMode: Text.WordWrap
    }

    Timer {
        id: meuTimer
        running: false
        interval: 300
        triggeredOnStart: false
        onTriggered: anim.start();
    }

    onWidthChanged: {
        meuTimer.restart();
    }

    ParallelAnimation {
        id: anim
        running: false

        SmoothedAnimation { target: txtInfo; property: "x"; to: root.margemEsquerda; velocity: 1080; }
        SmoothedAnimation { target: separador; property: "x"; to: root.margemEsquerda; velocity: 1200 }
        SmoothedAnimation { target: txtDescricao; property: "x"; to: root.margemEsquerda; velocity: 900 }

        onCompleted: {
            root.exibido();
        }
    }

    Component.onCompleted: {

    }
}
