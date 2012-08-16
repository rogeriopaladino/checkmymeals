import QtQuick 1.1
import com.nokia.symbian 1.1
import "cores.js" as Cores
import "main.js" as MainScript

Page {
    id: page
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked: {
                page.pageStack.pop();
            }
        }
    }

    signal infoPagina(string local)

    onVisibleChanged: {
        infoPagina("Ajuda");
    }

    Flickable {
        id: flick        
        width: parent.width; height: parent.height
        contentWidth: parent.width; contentHeight: col.height

        Column {
            id: col
            width: parent.width * 0.9
            spacing: 4
            anchors.horizontalCenter: parent.horizontalCenter

            ItemTextoAjudaPage {
                texto: "Com o CheckMyMeals Mobile você ficará sempre preparado para economizar no almoço e evitar surpresas na hora do pagamento."
            }

            ItemTextoAjudaPage {
                texto: "Vamos começar explicando o significado das opções da toolbar:"
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///toolbar_new"
                texto: "Você irá para a tela de cadastro de cartões."
                mostrarFundoNoIcone: true
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///toolbar_ajuda"
                texto: "Acesso a esta tela de ajuda."
                mostrarFundoNoIcone: true
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///toolbar_ok"
                texto: "Confirma as informações da tela e volta para anterior."
                mostrarFundoNoIcone: true
            }

            ItemTextoAjudaPage {
                texto: "Agora iremos falar um pouco sobre os ícones de status. Eles representam algumas informações importantes sobre o seu cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///caiu"
                texto: "Informa quando e quanto crédito foi depositado no cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///money"
                texto:"Valor do crédito disponível no cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///grafico"
                texto: "Valor médio que você poderá utilizar diariamente no cartão durante trinta dias ou até a próxima recarga."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///carrinho_compra"
                texto: "Última compra efetuada no cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///calendario"
                texto: "Data e valor da próxima recarga programada para o cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///favorito"
                texto: "Estabelecimento em que o cartão foi mais vezes utilizado."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///campeao"
                texto: "Maior gasto já computado no cartão."
            }

            ItemTextoAjudaPage {
                texto: "Para começar a utilizar o CheckMyMeals é muito simples."
            }

            ItemTextoAjudaPage {
                texto: "Basta você adicionar um número de cartão (Visa Vale ou Vale Alimentação). Depois manter o dedo sobre o cartão e escolher \"Atualizar\" nas opções que aparecerão no menu de contexto."
            }

            ItemTextoAjudaPage {
                texto: "Pronto! As informação serão carregadas e computadas em seu aparelho. Agora é só seguir atualizando diariamente para ter um histório detalhado de créditos e débitos de seus cartões!"
            }
        }
    }
}
