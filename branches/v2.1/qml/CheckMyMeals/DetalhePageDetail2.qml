// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1
import "cores.js" as Cores

Rectangle {
    width: lstDetalhesTotal.width; height: lstDetalhesTotal.height
    color: Cores.COR_FUNDO

    ListView {
        id : list
        clip: true
        model: compraModel
        spacing: 2
        anchors { fill: parent }
        delegate: DetalheInfo { id: delegateCompra;  corBackground: Cores.COR_FUNDO }
        section.property: "dataCompra"
        section.delegate: Rectangle {
            width: list.width; height: childrenRect.height
            color: Cores.COR_FUNDO

            function secaoParaData() {
                var partes = section.split("-");
                var dataConvertida = partes[0] + "/" + partes[1] + "/" + partes[2];
                return new Date(dataConvertida);
            }

            Text {
                text: Qt.formatDate(secaoParaData(), "dd/MM/yyyy")
                color: Cores.COR_TEXTO
                font.pixelSize: 20
            }
        }
        footer: Rectangle {
            width: list.width; height: childrenRect.height + 20
            visible: util.versaoFree
            color: Cores.COR_FUNDO

            Text {
                width: parent.width
                text: "Na versão gratuita, apenas as últimas 5 utilizações podem ser visualizadas!"
                color: Cores.COR_TEXTO
                font.pixelSize: 18
                wrapMode: Text.WordWrap
            }
        }
    }

    ScrollDecorator {
        flickableItem: list
        anchors { right: list.right; top: list.top }
    }
}
