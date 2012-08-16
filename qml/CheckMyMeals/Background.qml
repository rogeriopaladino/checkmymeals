// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "cores.js" as Cores

Rectangle {
    id: root
    color: "black"

    function corInicial() {
        root.toColor = "#232633";
    }

    function corAleatoria() {
        var r = Math.round(Math.random(Date.now) * Cores.cores.length - 1);
        r = (r < 0 ? 0 : r);
        root.toColor = Cores.cores[r];
    }

    Component.onCompleted: corInicial();

    property int margemEsquerda: 13
    property int margemSuperior: 5
    property int margemInferior: 5
    property int margemDireita: 2

    property variant objetoParaCarregar

    property string toColor

    onToColorChanged: {
        /*rectB.color = root.toColor;
        rectL.color = root.toColor;
        rectT.color = root.toColor;
        rectR.color = root.toColor;*/
        root.color = root.toColor;
    }

    Behavior on color {
        ColorAnimation { duration: 750 }
    }

    onObjetoParaCarregarChanged: {
        if (root.objetoParaCarregar !== "undefined")
            objetoParaCarregar.parent = pai;
    }

    Rectangle {
        id: rectInterno
        radius: 10
        anchors { fill: parent; leftMargin: margemEsquerda; topMargin: margemSuperior; bottomMargin: margemInferior; rightMargin: margemDireita }
        color: "black"

        Item {
            id: pai
            anchors { fill: parent; leftMargin: 2; topMargin: 2; bottomMargin: 2; }
        }
    }
}
