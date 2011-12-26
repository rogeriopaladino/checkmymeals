import QtQuick 1.1
import com.nokia.symbian 1.1
import "cores.js" as Cores

Window {
    id: mainWindow

    StatusBar {
        id: status
        anchors.top: parent.top        
        z: 1

        Rectangle {
            width: parent.width/3.5; height: parent.height
            color: "black"

            SequentialAnimation {
                id: anim1

                NumberAnimation { target: txtInfoPagina; property: "opacity"; to: 0; duration: 200 }
                PropertyAction {id: propAnim; target: txtInfoPagina; property: "text"; value: "" }
                NumberAnimation { target: txtInfoPagina; property: "opacity"; to: 1; duration: 200 }
            }

            Text {
                id: txtInfoPagina;                
                font { pixelSize: 14; bold: false }
                anchors { verticalCenter: parent.verticalCenter }
                color: "white"
            }
        }
    }

    Rectangle {
        width: parent.width; height: parent.height;
        color: Cores.COR_FUNDO
    }

    PageStack {
        id: pages
        toolBar: myTool
        anchors { top: status.bottom; left: parent.left; right: parent.right; bottom: myTool.top }        
    }    

    ToolBar {
        id: myTool
        anchors { bottom: parent.bottom; left: parent.left; right: parent.right }        
    }

    Connections {
        id: teste
        target: pages.currentPage
        ignoreUnknownSignals: true

        onInfoPagina: {
            propAnim.value = local;
            anim1.start();
        }
    }

    Component.onCompleted: {
        pages.push(Qt.resolvedUrl("MainPage.qml"));
    }
}

