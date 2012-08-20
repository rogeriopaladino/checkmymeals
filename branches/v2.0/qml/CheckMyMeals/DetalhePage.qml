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
                //compraModel.LimparCompras();
                page.pageStack.pop().destroy(500);
            }
        }
    }

    signal infoPagina(string local);

    onVisibleChanged: {
        if (visible) {
            infoPagina("Detalhes");

            if (compraModel.tamanho === 0)
                msgAlertaSemCompra.open();
        }
    }

    //property string numero : "";

    /*onNumeroChanged: {
        if (numero != "") {
            compraModel.Carregar(numero);
            if (compraModel.tamanho === 0)
                msgAlertaSemCompra.open();
        } else {
            page.pageStack.pop();
        }
    }*/

    Rectangle {
        id: headerDetalhes
        color: Cores.COR_FUNDO
        height: parent.height / 3
        anchors { left: parent.left; top: parent.top; right: parent.right; margins: 2 }
        border.color: Cores.COR_BORDA
        radius: 10

        ListView {
            id: lstHeader
            model: cartaoProxy
            anchors { fill: parent; }
            interactive: false
            delegate: DetalheHeaderInfo {
                width: lstHeader.width; height: headerDetalhes.height
            }
        }
    }

    ListView {
        id : list
        clip: true
        model: compraModel
        anchors { left: parent.left; top: headerDetalhes.bottom; right: parent.right; bottom: parent.bottom }
        delegate: DetalheInfo { }
    }

    ScrollDecorator {
        flickableItem: list
        anchors { right: list.right; top: list.top }
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
