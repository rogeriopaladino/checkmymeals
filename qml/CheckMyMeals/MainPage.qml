import QtQuick 1.1
import com.nokia.symbian 1.1
import com.nokia.extras 1.1

import "main.js" as MainScript

Page {
    id: page
    objectName: "MainPage"
    tools: ToolBarLayout {        
               ToolButton {
                   iconSource: "qrc:///fechar"
                   onClicked: {
                       Qt.quit();
                   }
               }
               ToolButton {
                   iconSource: "qrc:///toolbar_new"
                   QueryDialog {
                       id: msgVerFreeAddCartao
                       titleText: "Versão gratuíta"
                       message: "Compre a versão completa para cadastrar quantos cartões quiser! <br />"
                       acceptButtonText: "Ok"
                   }
                   onClicked: {
                       if (cartaoModel.tamanho >= 2 && util.versaoFree) {
                           msgVerFreeAddCartao.open();
                       } else {
                           var componente = Qt.createComponent("CadCartaoPage.qml");
                           var obj = componente.createObject(page);
                           obj.ok.connect(function() {
                                              cartaoModel.AdicionarCartao(obj.numero.replace(/-/g, ""), obj.descricao, obj.bandeira);
                                          });
                           MainScript.PushNaPilha(page.pageStack, obj);
                       }
                   }
               }
               ToolButton {
                   iconSource: "qrc:///toolbar_reload"
                   onClicked: {
                       queryAtualizarTodos.open()
                   }
               }

               /*ToolButton {
                   iconSource: "toolbar-search"
                   onClicked: {

                   }
               }*/

               ToolButton {
                   iconSource: "qrc:///toolbar_ajuda"
                   onClicked: {
                       var componente = Qt.createComponent("AjudaPage.qml");
                       var obj = componente.createObject(page);
                       MainScript.PushNaPilha(page.pageStack, obj);
                   }
               }
               ToolButton {
                   iconSource: "qrc:///toolbar_info"
                   onClicked: {
                       var componente = Qt.createComponent("AboutPage.qml");
                       var obj = componente.createObject(page);
                       MainScript.PushNaPilha(page.pageStack, obj);
                   }
               }
           }   

    signal infoPagina(string local)

    property string corBackground: "black"

    /*Connections {
        target: visa

        onIniciandoConsulta: {

        }

        //a consulta foi finalizada e o objeto processador já foi conectado aos modelos
        onConsultaFinalizada: {

        }

        onConsultaCancelada: {            
            timerInfo.adicionarMensagem("Consulta cancelada!", "qrc:///atencao", 2000);
        }

        onErroConexao: {
            erroConexao.open();
        }
    }*/

    Connections {
            target: conexao

            onIniciandoConsulta: {

            }

            //a consulta foi finalizada e o objeto processador já foi conectado aos modelos
            onConsultaFinalizada: {

            }

            onConsultaCancelada: {
                timerInfo.adicionarMensagem("Consulta cancelada!", "qrc:///atencao", 2000);
            }

            onErroConexao: {
                erroConexao.open();
            }
        }

    Connections {
        target: processador

        onCartaoInvalido: {

        }

        onSistemaForaDoAr: {
            //visa.Cancelar();
            conexao.Cancelar();
            erroConexao.open();
        }
        onCartaoAtualizado: {

        }

        onNenhumaCompraEfetuada: {

        }
    }

    Connections {
        target: cartaoModel

        onNovoCartaoAdicionado: {
            lstCartoes.positionViewAtIndex(indice, ListView.Contain);
        }
    }

    FilaInformacao {
        id: timerInfo
    }

    Connections {
        id: cnx
        target: pageStack

        onCurrentPageChanged: {
            if (pageStack.currentPage.objectName === "MainPage") {
                cartaoProxy.LimparFiltros();                
            }
        }
    }

    ListView {
        id: lstCartoes
        anchors.fill: parent
        spacing: 2
        model: cartaoProxy
        delegate: MainInfoCartao {
            quantidadeCartao: cartaoModel.tamanho
            corBackground: page.corBackground

            onClick: {
                MainScript.cartaoMainSelecionado = "";
                MainScript.bandeiraSelecionada = -1;
                var componente = Qt.createComponent("DetalhePage.qml");                
                if (componente.status == Component.Ready) {
                    var obj = componente.createObject(page);
                    if (obj !== null) {
                        cartaoProxy.SelecionarPorCartao(numero);
                        MainScript.PushNaPilha(page.pageStack, obj);
                    }
                } else if (componente.status == Component.Error) {
                    console.log("Erro::: " + componente.errorString());
                }
            }

            onDedoPressionado: {
                MainScript.cartaoMainSelecionado = numero;
                MainScript.bandeiraSelecionada = bandeira;
                ctxMenu.open();                
            }
        }
    }

    ScrollDecorator {
        flickableItem: lstCartoes
        anchors { right: lstCartoes.right; top: lstCartoes.top; }
    }

    onVisibleChanged: {
        infoPagina("Principal");        
    }

    InfoText {
        id: helpMainText
        width: parent.width
        height: parent.height
        visible: cartaoModel.tamanho == 0
        info: "Seja Bem-vindo ao CheckMyMeals!<br>Adicione novos cartões e comece a controlar seus gastos!<br>Clique no botão \"?\"\ para entender como tudo funciona!" +
              (util.versaoFree ? "<br /><br /><i>Versão gratuita.</i>" : "")
    }

    QueryDialog {
        id: msgConfirmarExclusao
        titleText: "Excluir"
        message: "Deseja mesmo excluir o cartão " + MainScript.cartaoMainSelecionado + "?<br/>Todos os históricos de compras e benefícios também serão excluídos!<br />"
        icon: "qrc:///questao"
        acceptButtonText: "Sim"
        rejectButtonText: "Não"
        onAccepted: {
            cartaoModel.RemoverCartao(MainScript.cartaoMainSelecionado);
        }
    }

    ContextMenu {
        id: ctxMenu
        MenuLayout {
            MenuItem {
                text: "Atualizar"
                onClicked: {
                    //visa.Consultar(MainScript.cartaoMainSelecionado);
                    conexao.Consultar(MainScript.cartaoMainSelecionado, MainScript.bandeiraSelecionada);
                }
            }
            MenuItem {
                text: "Editar"
                onClicked: {
                    var componente = Qt.createComponent("CadCartaoPage.qml");
                    var obj = componente.createObject(page);
                    obj.modoEditar(MainScript.cartaoMainSelecionado);
                    obj.ok.connect(function() {
                                       cartaoModel.AtualizarCartao(obj.numero.replace(/-/g, ""), obj.descricao);
                                       timerInfo.adicionarMensagem("Edição finalizada!", "qrc:///ok", 1500);
                                   });
                    MainScript.PushNaPilha(page.pageStack, obj);
                }
            }
            MenuItem {
                text: "Excluir"
                onClicked: {
                    msgConfirmarExclusao.open();
                }
            }
        }
    }

    QueryDialog {
        id: queryAtualizarTodos
        titleText: "Atualizar"
        message: "Atualizar os dados de todos os cartões cadastrados?<br />"
        acceptButtonText: "Ok"
        rejectButtonText: "Cancelar"
        onAccepted: {            
            /*var cartoes = cartaoModel.cartoesCadastrados;
            if (cartoes.length > 0) {
            for(var i = 0; i < cartoes.length; i++)
                visa.AdicionarParaConsulta(cartoes[i], true);
            visa.IniciarCosulta();
            } else {
                querySemCartoes.open();
            }*/
            var cartoes = cartaoModel.cartoesCadastrados;
            if (cartoes.length > 0)
            {
                for(var i = 0; i < cartoes.length; i+=2)
                {
                    var numeroCartao = cartoes[i];
                    var bandeira = cartoes[i+1]
                    console.log("Cartão " + numeroCartao + " e bandeira " + bandeira);
                    conexao.AdicionarParaConsulta(numeroCartao, bandeira);
                }
                conexao.IniciarConsulta();
            } else {
                querySemCartoes.open();
            }
    }

        QueryDialog {
            id: querySemCartoes
            titleText: "Atualizar"
            message: "Não há cartões cadastrados!"
            acceptButtonText: "Ok"
            onAccepted: {
                querySemCartoes.close();
            }
        }
    }

    Dialog {
        id: processando
        title: Item {
            anchors.fill: parent

            Text {
                text: "Atualizando"
                color: "white"
                font { pixelSize: 20; bold: true}
                anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter }
            }

            Image {
                source: "qrc:///ampulheta"
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        content: ProgressBar {
            indeterminate: true
            width: parent.width * 0.85
            anchors { horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter }
        }
        buttons: ButtonRow {
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Cancelar"
                onClicked: {
                    visa.Cancelar();
                }
            }
        }
    }

    QueryDialog {
        id: erroConexao
        titleText: "Erro de conexão"
        message: "Houve um problema de conexão com o servidor do Visa Vale!<br />Tente novamente mais tarde."
        icon: "qrc:///erro"
        acceptButtonText: "OK"
        onAccepted: erroConexao.close();
    }

    onWidthChanged: {
        MainScript.screenWidth = width;
    }

    onHeightChanged: {
        MainScript.screenHeight = height;
    }

    /*Timer {
        interval: 1000
        triggeredOnStart: false
        running: true
        repeat: true

        onTriggered: {
            painelInfo.adicionarMensagem("Oi!");
        }
    }*/

    PainelComBotao {
        id: painelInfo        

        onCancelar: {
            visa.Cancelar();
        }
    }
}
