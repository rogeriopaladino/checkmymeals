// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1

Page {
    id: root

    property bool mostrarAbertura: false
    property string infoHeader: ""
    property alias tituloAbertura : somenteInfo.titulo
    property alias descricaoAbertura: somenteInfo.descricao

    signal infoPagina(string local);

    onStatusChanged: {
        if (status == PageStatus.Activating && root.mostrarAbertura) {
            somenteInfo.abrir();
        }
    }

    onVisibleChanged: {
         if (visible && root.infoHeader != "")
             root.infoPagina(root.infoHeader);
    }

    ModalMostraInfoESome {
        id: somenteInfo
        titulo: ""
        descricao: ""
    }
}
