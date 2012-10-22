// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

ModalDialogBase {
    id: root
    property alias titulo : infoBack.textoInfo
    property alias descricao: infoBack.textoDescricao

    onMostrarCompleto: {
        infoBack.iniciar();
    }

    onFecharCompleto: {

    }

    InfoAnimadoBackground {
        id: infoBack
        y: parent.height / 2 - infoBack.height / 2
        onAnimacaoFinalizada: {
            if (ine) {
                tmr1.start();
            } else {
                root.fechar();
            }
        }
    }

    Timer {
        id: tmr1
        interval: 750
        running: false
        triggeredOnStart: false
        onTriggered: {
            infoBack.resetar();
        }
    }    
}
