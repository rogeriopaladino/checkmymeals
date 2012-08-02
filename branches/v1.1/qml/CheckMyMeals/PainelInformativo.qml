// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    color: "gray"
    opacity: 0.7

    function adicionarMensagem(mensagem) {
        lstModel.append({info: mensagem});
    }

    ListModel {
        id: lstModel
    }

    ListView {
        anchors.fill: parent
        model: lstModel
        delegate: Text {
            text: info
            color: "red"
        }
    }
}
