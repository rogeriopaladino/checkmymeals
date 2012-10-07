// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "cores.js" as Cores

BackgroundBase {
    id: root
    color: "black"

    property variant objetoParaCarregar

    onObjetoParaCarregarChanged: {
        if (root.objetoParaCarregar !== null)
            objetoParaCarregar.parent = pai;
    }

    Component.onCompleted: {
        root.margemEsquerda = 13;
        root.margemSuperior = 5;
        root.margemInferior = 5;
        root.margemDireita = 2;
    }

    Rectangle {
        id: rectInterno
        radius: 10
        anchors { fill: parent; leftMargin: margemEsquerda; topMargin: margemSuperior; bottomMargin: margemInferior; rightMargin: margemDireita }
        color: Cores.COR_FUNDO

        Item {
            id: pai
            anchors { fill: parent; leftMargin: 2; topMargin: 2; bottomMargin: 2; }
        }
    }
}
