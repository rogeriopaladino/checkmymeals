import QtQuick 1.1

Item {
    id: root
    width: parent.width; height: parent.height

    property int maxTop: 100

    onMaxTopChanged: {
        calularPosicaoImagem();
    }

    function animar() {
        anim1.restart();
    }

    function calularPosicaoImagem() {
        yAnim.to = (root.width > root.height ? 0 : root.maxTop);
    }

    Image {
        id: img
        x: 0
        y: 0
        source: "qrc:///card_grande"

        MouseArea {
            anchors.fill: parent
            drag.target: parent
            drag.axis: Drag.XandYAxis
            onPressed: {
                anim1.stop();
            }
            onReleased: {
                anim1.restart();
            }
        }
    }

    ParallelAnimation {
        id: anim1
        running: false
        SpringAnimation { target: img; property: "x"; to: parent.width * 0.85 - img.width; damping: 0.1; mass: 3.2; spring: 1 }
        SpringAnimation { id: yAnim; target: img; property: "y"; to: (root.width > root.height ? 0 : root.maxTop); damping: 0.1; mass: 3.2; spring: 1 }
    }

    onHeightChanged: {
        calularPosicaoImagem();
        anim1.restart();
    }

    onWidthChanged: {
        calularPosicaoImagem();
        anim1.restart();
    }
}
