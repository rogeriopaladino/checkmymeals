import QtQuick 1.1
import com.nokia.symbian 1.1
import "cores.js" as Cores

Item {
    width: parent.width
    height: parent.height

    property alias info : txt.text

    CartaoAnimado {
        id: cartaoAnimado
        visible: false
        z: 1
    }

    SequentialAnimation {
        id: anim1
        running: true
        NumberAnimation { target: txt; property: "opacity"; to: 1; duration: 200 }
        onCompleted: {
            cartaoAnimado.visible = true;
            cartaoAnimado.animar();
        }
    }

    Text {
        id: txt
        width: parent.width * 0.85
        anchors.centerIn: parent
        font.pixelSize: 20
        color: Cores.COR_TEXTO
        wrapMode: Text.WordWrap
        opacity: 0
    }
}
