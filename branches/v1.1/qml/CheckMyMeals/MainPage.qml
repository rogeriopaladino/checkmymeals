import QtQuick 1.1
import com.nokia.symbian 1.1
import com.nokia.extras 1.1

import "main.js" as MainScript

Page {
    id: page    
    tools: ToolBarLayout {        
               ToolButton {
                   iconSource: "toolbar-back"
                   onClicked: {
                       Qt.quit();
                   }
               }
               ToolButton {                   
                   iconSource: "qrc:///toolbar_new"
                   onClicked: {
                       var componente = Qt.createComponent("CadCartaoPage.qml");
                       var obj = componente.createObject(page);
                       obj.ok.connect(function() {
                                          cartaoModel.AdicionarCartao(obj.numero.replace(/-/g, ""), obj.descricao);
                                      });
                       MainScript.PushNaPilha(page.pageStack, obj);
                   }
               }
               ToolButton {
                   iconSource: "toolbar-refresh"
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

    Connections {
        target: visa

        onIniciandoConsulta: {
            console.debug("Iniciando a consulta..." + cartao);                        
            //painelInfo.mostrar(true);
            //processando.open();
        }

        onIniciandoConsultaLote: {
            //processando.open();            
            //painelInfo.mostrar(true);
        }

        onConsultaLoteFinalizada: {
            //processando.close();
            //painelInfo.mostrar(fasle);
        }

        //a consulta foi finalizada e o objeto processador já foi conectado aos modelos
        onConsultaFinalizada: {
            //processando.close();
        }

        onConsultaCancelada: {
            //processando.close();
            timerInfo.adicionarMensagem("Consulta cancelada!", "qrc:///atencao", 2000);
        }

        onErroConexao: {
            //processando.close();
            //painelInfo.mostrar(false);
            erroConexao.open();
        }
    }

    Connections {
        target: processador

        onCartaoInvalido: {
            //console.debug("Oooops! Cartão inválido!");
            //timerInfo.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao) + " inválido!", "qrc:///erro", 2000);
            //painelInfo.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao) + " inválido!");
        }

        onSistemaForaDoAr: {
            visa.Cancelar();
            //processando.close();
            erroConexao.open();            
        }
        onCartaoAtualizado: {
            //console.debug("Cartão " + cartao + " atualizado!");
            //timerInfo.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao) + " atualizado!", "qrc:///ok", 2000);
            //painelInfo.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao) + " atualizado!");
        }

        onNenhumaCompraEfetuada: {
            //console.debug("Cartão " + cartao  + " não tem novas compras!");
            //timerInfo.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao)  + " não tem novas compras!", "qrc:///ok", 2000);
            //painelInfo.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao)  + " não tem novas compras!");
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

    ListView {
        id: lstCartoes
        anchors.fill: parent
        model: /*cartaoModel*/cartaoProxy
        delegate: MainInfoCartao {
            quantidadeCartao: cartaoModel.tamanho

            onClick: {
                MainScript.cartaoMainSelecionado = "";
                var componente = Qt.createComponent("DetalhePage.qml");
                var obj = componente.createObject(page);
                obj.numero = numero;
                MainScript.PushNaPilha(page.pageStack, obj);
            }

            onDedoPressionado: {
                MainScript.cartaoMainSelecionado = numero;
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
        info: "Seja Bem-vindo ao CheckMyMeals!<br>Adicione novos cartões e comece a controlar seus gastos!<br>Clique no botão \"?\"\ para entender como tudo funciona!"
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
                    visa.Consultar(MainScript.cartaoMainSelecionado);
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
        //icon: "toolbar-refresh"
        message: "Atualizar os dados de todos os cartões cadastrados?<br />"
        acceptButtonText: "Ok"
        rejectButtonText: "Cancelar"
        onAccepted: {
            var cartoes = cartaoModel.cartoesCadastrados;
            for(var i = 0; i < cartoes.length; i++)
                visa.AdicionarParaConsulta(cartoes[i], true);
            visa.IniciarCosulta();
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
        anchors.fill: parent        
    }

    BusyIndicator {
        id: busy
        running: busy.visible
        visible: false
        anchors.centerIn: parent
    }
}
