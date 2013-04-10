// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1

Page {
    id: root

    property bool mostrarAbertura: false
    property string infoHeader: ""
    property string tituloAbertura : ""
    property string descricaoAbertura: ""

    signal infoPagina(string local);

    onStatusChanged: {
        if (status == PageStatus.Activating && root.mostrarAbertura) {

        }
    }

    onVisibleChanged: {
         if (visible && root.infoHeader != "")
             root.infoPagina(root.infoHeader);
    }    
}
