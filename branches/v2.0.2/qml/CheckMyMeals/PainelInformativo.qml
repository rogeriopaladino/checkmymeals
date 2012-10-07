// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1
import com.nokia.extras 1.1
import "cores.js" as Cores

Item {
    id: root

    property alias lista: lst

    Component.onCompleted: {
        cache.preparar();
        root.mostrar(false);
    }

    Component.onDestruction: {
        cache.voltarAoNormal();
    }

    Rectangle {
        anchors.fill: parent
        color: Cores.COR_FUNDO_PRETO
        opacity: 0.7
    }

    MouseArea {
        anchors.fill: parent
    }

    QtObject {
        id: cache

        property variant oldParent

        function preparar() {            
            oldParent = root.parent;
            while (root.parent.parent) {                
                console.debug("Pai do pai e: " + root.parent.parent);
                root.parent = root.parent.parent;
                if (root.parent.toString().indexOf("QDeclarativeItem") != -1 && root.parent.toString().indexOf("window") != -1)
                    break;
            }
            //verificar se há um statusbar no pai
            var fazerUmFill = true;
            for (var i = 0; i < root.parent.children.length; i++) {
                var item =  root.parent.children[i];
                if (item.toString().indexOf("StatusBar") != -1) {
                    console.debug(item);
                    root.anchors.top = item.bottom;
                    root.anchors.left = root.parent.left;
                    root.anchors.right = root.parent.right;
                    root.anchors.bottom = root.parent.bottom;
                    fazerUmFill = false;
                    break;
                }
            }
            if (fazerUmFill)
                root.anchors.fill = root.parent;
        }

        function voltarAoNormal() {
            root.parent = oldParent;
        }
    }

    function mostrar(acao) {
        root.visible = acao;
    }

    function adicionarMensagem(mensagem) {
        lstModel.append({info: mensagem});        
    }

    function limpar() {
        lstModel.clear();
    }

    ListModel {
        id: lstModel
    }

    ListView {
        id: lst
        anchors { left: parent.left; right: parent.right; top: parent.top; bottom: parent.bottom; margins: 5; topMargin: 20; bottomMargin: 60 }
        height: parent.height
        model: lstModel
        clip: true
        snapMode: ListView.SnapOneItem
        spacing: 5
        delegate: Item {
            width: root.width; height: 50
            id: delegateInformation

            Row {
                anchors.fill: parent
                spacing: 5

                Image {                    
                    source: "qrc:///info"
                    width: 32; height: 32
                }

                Text {
                    text: info
                    width: parent.width - 37
                    color: "#ffffff"
                    font.pixelSize: 22
                    wrapMode: Text.WordWrap
                }
            }

            ListView.onAdd: {
                delegateInformation.state = "INICIO";
                delegateInformation.state = "ADICIONADO";
            }

            states: [
                State {
                    name: "INICIO"
                    PropertyChanges { target: delegateInformation; x: -delegateInformation.width }
                },
                State {
                    name: "ADICIONADO"
                    PropertyChanges { target: delegateInformation; x: 0 }
                }
            ]

            transitions: [
                Transition { from: "INICIO"; to: "ADICIONADO"; reversible: true
                    SequentialAnimation {
                        SpringAnimation { property: "x"; spring:2; mass: 2; damping: 0.2; epsilon: 1.55; modulus: 0; velocity: 0 }
                    }
                }
            ]
        }
    }

    ScrollBar {
        id: scroll
        flickableItem: lst
        anchors.right: parent.right
        policy: Symbian.ScrollBarWhenNeeded
    }
}
