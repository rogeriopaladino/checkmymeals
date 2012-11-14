// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root;
    height: (rectTotal.height > 0 ? rectTotal.height : rectCabecalho.height);

    property string titulo : ""
    property color corBorda : "red"
    property color corFundo: "black"
    property color corTexto: "white"

    onChildrenChanged: {
        var filhos = root.children;
        for (var i = 0; i < filhos.length; i++)
            if (filhos[i] != rectCabecalho && filhos[i] != rectTotal)
                filhos[i].parent = colPai;
    }

    Rectangle {
        id: rectTotal
        width: parent.width; height: colPai.height + colPai.anchors.topMargin + colPai.anchors.bottomMargin
        x: 5; y: 10;
        border { width: 1; color: root.corBorda }
        color: root.corFundo

        Column {
            id: colPai
            anchors { left: parent.left; top: parent.top; right: parent.right; margins: 15; }
        }
    }

    Rectangle {
        id: rectCabecalho
        y: 5
        width: childrenRect.width + 10; height: childrenRect.height
        border { width: 1; color: root.corBorda }
        color: root.corFundo

        Text {
            text: root.titulo
            color: root.corTexto
            x: 5
        }
    }
}
