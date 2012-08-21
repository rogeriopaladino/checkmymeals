import QtQuick 1.1
import com.nokia.symbian 1.1
import "cores.js" as Cores

Page {
    id: page
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked:{
                page.pageStack.pop();
            }
        }
    }

    signal infoPagina(string local);

    CartaoAnimado {
        id: cartaoAnimado
        maxTop: 80
        z: 1
    }

    onVisibleChanged: {
        if (visible) {
            infoPagina("Sobre");
            cartaoAnimado.animar();
        }
    }

    Column {
        id: col
        width: parent.width * 0.8
        anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter }

        ItemTextoAjudaPage {
            texto: "CheckMyMeals"
            font { pixelSize: 25; bold: true }
        }

        ItemTextoAjudaPage {
            texto: "Versão 2.0"
            font { italic: true }
        }

        ItemTextoAjudaPage {
            texto: "Autor: Rogério Paladino"
            font { italic: true }
        }

        ItemTextoAjudaPage {
            texto: "Contato: segaaaa@gmail.com"
            font { italic: true }
        }

        ItemTextoAjudaPage {
            texto: "Este aplicativo organiza suas informações do Visa Vale e Vale Alimentação de uma maneira fácil e rápida."
        }
    }

    ItemTextoAjudaPage {
        width: parent.width
        texto: "Este aplicativo não tem nenhuma ligação com a Visa ou qualquer outra organização."
        font { pixelSize: 10 }
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter }
    }
}
