import QtQuick 1.1
import com.nokia.symbian 1.1
import "main.js" as MainScript
import com.rogerio.model 1.0

Page {
    id: page
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked: {
                compraModel.LimparCompras();
                page.pageStack.pop().destroy(1000);
            }
        }
    }

    signal infoPagina(string local);

    onVisibleChanged: {
        infoPagina("Detalhes");
    }

    property string numero : "";

    onNumeroChanged: {
        if (numero != "") {
            compraModel.Carregar(numero);
            if (compraModel.tamanho === 0)
                msgAlertaSemCompra.open();
        } else {
            page.pageStack.pop();
        }
    }

    ListView {
        id : list
        model: compraModel
        anchors.fill: parent
        delegate: DetalheInfo { }
    }

    ScrollDecorator {
        flickableItem: list
        anchors { right: list.right; top: list.top }
    }

    QueryDialog {
        id: msgAlertaSemCompra
        titleText: "Sem compras"
        message: "O cartão não possui nenhuma compra!"
        icon: "qrc:///atencao"
        acceptButtonText: "OK"
        onAccepted: {
            page.pageStack.pop().destroy(1000);
        }
    }
}
