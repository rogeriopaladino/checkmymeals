// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root
    width: parent.width
    height: 120

    property string textoInfo: ""
    property string textoDescricao: ""
    property int margemEsquerda: 15

    Text {
        id: txtInfo
        color: platformStyle.colorNormalLink
        text: root.textoInfo
        font { pixelSize: 30; italic: true }
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
        font { pixelSize: 20 }
        x: txtInfo.x; y: separador.y + separador.height + 1
        wrapMode: Text.WordWrap
    }

    Timer {
        id: meuTimer
        running: true
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

        SmoothedAnimation { target: txtInfo; property: "x"; to: root.margemEsquerda; velocity: 780; }
        SmoothedAnimation { target: separador; property: "x"; to: root.margemEsquerda; velocity: 900 }
        SmoothedAnimation { target: txtDescricao; property: "x"; to: root.margemEsquerda; velocity: 700 }
    }

    Component.onCompleted: {

    }
}
