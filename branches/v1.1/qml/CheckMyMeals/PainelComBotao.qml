// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1

PainelInformativo {
    id: root

    Button {
        anchors {  top: lista.bottom; horizontalCenter: parent.horizontalCenter }
        text: "Cancelar"
        onClicked: root.mostrar(false)
    }
}
