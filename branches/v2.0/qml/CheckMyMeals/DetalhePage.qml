import QtQuick 1.1
import com.nokia.symbian 1.1
import com.rogerio.model 1.0
import "main.js" as MainScript
import "cores.js" as Cores

Page {
    id: page
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked: {                
                page.pageStack.pop().destroy(500);
            }
        }
    }

    signal infoPagina(string local);
    property string corBackground : "black"

    onVisibleChanged: {
        if (visible) {
            infoPagina("Detalhes");
            if (compraModel.tamanho === 0)
                msgAlertaSemCompra.open();
        }
    }    

    VisualItemModel {
        id: visualModel

        Rectangle {
            width: lstDetalhesTotal.width; height: lstDetalhesTotal.height
            color: Cores.COR_INICIAL_BACKGROUND

            ListView {
                id: lstHeader
                model: cartaoProxy
                anchors { fill: parent; }
                delegate: DetalheHeaderInfo { }
            }
        }

        Rectangle {
            width: lstDetalhesTotal.width; height: lstDetalhesTotal.height
            color: Cores.COR_FUNDO

            ListView {
                id : list
                clip: true
                model: compraModel
                spacing: 2
                anchors { fill: parent }
                delegate: DetalheInfo { id: delegateCompra;  corBackground: page.corBackground }
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
            }

            ScrollDecorator {
                flickableItem: list
                anchors { right: list.right; top: list.top }
            }
        }
    }

    ListView {
        id: lstDetalhesTotal
        anchors.fill: parent
        model: visualModel
        currentIndex: 0
        preferredHighlightBegin: 0; preferredHighlightEnd: 0
        highlightRangeMode: ListView.StrictlyEnforceRange
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem
    }

    QueryDialog {
        id: msgAlertaSemCompra
        titleText: "Sem compras"
        message: "O cartão não possui nenhuma compra!<br />"
        icon: "qrc:///atencao"
        acceptButtonText: "OK"
        onAccepted: {
            page.pageStack.pop().destroy(500);
        }
    }
}
