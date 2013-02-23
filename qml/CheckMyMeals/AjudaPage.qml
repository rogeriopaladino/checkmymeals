import QtQuick 1.1
import com.nokia.symbian 1.1
import "cores.js" as Cores
import "main.js" as MainScript

PageBase {
    id: page
    mostrarAbertura: true
    infoHeader: "Ajuda"
    tituloAbertura: "Ajuda"
    descricaoAbertura: "Tire suas dúvidas!"
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked: {
                page.pageStack.pop();
            }
        }
    }


    onVisibleChanged: {
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
                mostrarFundoNoIcone: false
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///toolbar_ajuda"
                texto: "Acesso a esta tela de ajuda."
                mostrarFundoNoIcone: false
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///toolbar_reload"
                texto: "Atualizar todos os cartões cadastrados de uma só vez."
                mostrarFundoNoIcone: false
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///toolbar_ok"
                texto: "Confirma as informações da tela e volta para anterior."
                mostrarFundoNoIcone: false
            }

            ItemTextoAjudaPage {
                texto: "Agora iremos falar um pouco sobre os ícones de status. Eles representam algumas informações importantes sobre o seu cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///caiu_neg"
                texto: "Informa quando e quanto crédito foi depositado no cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///money_neg"
                texto:"Valor do crédito disponível no cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///grafico_neg"
                texto: "Valor médio que você poderá utilizar diariamente no cartão durante trinta dias ou até a próxima recarga."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///carrinho_compra_neg"
                texto: "Última compra efetuada no cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///calendario_neg"
                texto: "Data e valor da próxima recarga programada para o cartão."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///favorito_neg"
                texto: "Estabelecimento em que o cartão foi mais vezes utilizado."
            }

            ItemIconeAjudaPage {
                srcImagem: "qrc:///campeao_neg"
                texto: "Maior gasto já computado no cartão."
            }

            ItemTextoAjudaPage {
                texto: "Para começar a utilizar o CheckMyMeals é muito simples."
            }

            ItemTextoAjudaPage {
                texto: "Basta você adicionar um número de cartão (Visa Vale ou Vale Alimentação). Depois, manter o dedo sobre o cartão e escolher \"Atualizar\" nas opções que aparecerão no menu de contexto ou clicar sobre o ícone Atualizar da barra de tarefas."
            }

            ItemTextoAjudaPage {
                texto: "Pronto! As informação serão carregadas e computadas em seu smartphone."
            }

            ItemTextoAjudaPage {
                texto: "Dê um clique sobre um cartão e, na tela que se abriu, veja as informações detalhadas e estatísticas. Rolando a tela para a esquerda, você verá o histório de utilizações do cartão."
            }

            ItemTextoAjudaPage {
                texto: "Agora é só seguir atualizando diariamente para ter um histório detalhado de créditos e débitos de seus cartões!"
            }
        }
    }
}
