// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

ModalDialogBase {
    id: root
    property alias titulo : infoBack.textoInfo
    property alias descricao: infoBack.textoDescricao

    onMostrarCompleto: {
        infoBack.iniciar();
    }

    InfoAnimadoBackground {
        id: infoBack
        y: parent.height / 2 - infoBack.height / 2
        onExibido: {
            tmr.start();
        }
    }

    Timer {
        id: tmr
        interval: 1000
        running: false
        triggeredOnStart: false
        onTriggered: {
            root.fechar();
        }
    }
}
