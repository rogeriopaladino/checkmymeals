import QtQuick 1.1
import com.nokia.symbian 1.1
import com.rogerio.model 1.0
import "Quadradinho"
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

   Component.onCompleted: {
       somenteInfo.abrir();
   }

   ModalMostraInfoESome {
       id: somenteInfo
       titulo: "Detalhes"
       descricao: "Acompanhe os detalhes do cartão selecionado!"
   }

   onVisibleChanged: {
        if (visible) {
            infoPagina("Detalhes");
            if (compraModel.tamanho === 0)
                msgAlertaSemCompra.open();
        }
    }

    VisualItemModel {
        id: visualModel

        DetalhePageDetail1 {
            width: lstDetalhesTotal.width; height: lstDetalhesTotal.height
        }

        DetalhePageDetail2 {
            width: lstDetalhesTotal.width; height: lstDetalhesTotal.height
        }
    }

    ListView {
        id: lstDetalhesTotal
        anchors { fill: parent; bottomMargin: 14 }
        model: visualModel
        currentIndex: 0
        preferredHighlightBegin: 0; preferredHighlightEnd: 0
        highlightRangeMode: ListView.StrictlyEnforceRange
        orientation: ListView.Horizontal
    }

    QuadradinhoManager
    {
        anchors { top: lstDetalhesTotal.bottom; bottom: parent.bottom; horizontalCenter: parent.horizontalCenter; margins: 1 }
        quadrados: 2
        quadradoAtual: lstDetalhesTotal.currentIndex
    }

    QueryDialog
    {
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
