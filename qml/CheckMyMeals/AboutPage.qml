import QtQuick 1.1
import com.nokia.symbian 1.1
import "cores.js" as Cores

PageBase {
    id: page
    mostrarAbertura: true
    infoHeader: "Sobre"
    tituloAbertura: "Sobre"
    descricaoAbertura: "Veja os detalhes sobre o aplicativo!"
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked:{
                page.pageStack.pop();
            }
        }
    }

    CartaoAnimado {
        id: cartaoAnimado
        maxTop: 80
        z: 1
    }

    onVisibleChanged: {
        if (visible) {            
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
            texto: "Versão " + util.numeroVersao
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
            texto: "Este aplicativo organiza suas informações do Visa Vale, Vale Alimentação e Ticket de uma maneira fácil e rápida."
        }

        ItemTextoAjudaPage{
            visible: util.versaoFree
            texto: "Esta é uma versão gratuita do aplicativo. Compre a versão completa; dê seu suporte ao desenvolvedor."
        }
    }

    ItemTextoAjudaPage {
        width: parent.width
        texto: "Este aplicativo não tem nenhuma ligação e nenhum suporte das bandeiras Visa ou Ticket."
        font { pixelSize: 10 }
        anchors { bottom: parent.bottom; horizontalCenter: parent.horizontalCenter }
    }
}
