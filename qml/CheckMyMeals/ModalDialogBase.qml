// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1
import com.nokia.extras 1.1

Item {
    id: root
    //clip: true

    signal mostrarCompleto()

    Component.onCompleted: {        
        cache.preparar();
        root.mostrar(false);
    }

    Component.onDestruction: {
        cache.voltarAoNormal();
    }

    Rectangle {
        id: rectCor
        anchors.fill: parent
        color: platformStyle.colorNormalDark
        opacity: 0.90
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
                //console.debug("Pai do pai e: " + root.parent.parent);
                root.parent = root.parent.parent;
                if (root.parent.toString().indexOf("QDeclarativeItem") != -1 && root.parent.toString().indexOf("window") != -1)
                    break;
            }
            //verificar se há um statusbar no pai
            var fazerUmFill = true;
            var maiorZ = 0;
            var i = 0;
            for (i = 0; i < root.parent.children.length; i++) {
                var item = root.parent.children[i];
                if (item.toString().indexOf("StatusBar") != -1) {                    
                    //console.debug("Filhos do parente: " + item.toString());
                    root.anchors.top = item.bottom;
                    root.anchors.left = root.parent.left;
                    root.anchors.right = root.parent.right;
                    root.anchors.bottom = root.parent.bottom;                    
                    fazerUmFill = false;                    
                }
                if (item.z > maiorZ)
                    maiorZ = item.z;
            }
            root.z = (maiorZ == 0 ? 2 : maiorZ);
            if (fazerUmFill)
                root.anchors.fill = root.parent;
        }

        function voltarAoNormal() {
            root.parent = oldParent;
        }        
    }

    function abrir() {
        mostrar(true);
        mostrarCompleto();
    }

    function fechar() {
        mostrar(false);
    }

    function mostrar(acao) {
        root.visible = acao;
    }           
}
