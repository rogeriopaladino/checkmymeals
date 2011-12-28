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
            processando.open();
        }

        //a consulta foi finalizada e o objeto processador já foi conectado aos modelos
        onConsultaFinalizada: {            
            processando.close();
        }

        onConsultaCancelada: {
            processando.close();
            timerInfo.adicionarMensagem("Consulta cancelada!", "qrc:///atencao", 2000);
        }

        onErroConexao: {
            processando.close();
            erroConexao.open();
        }
    }

    Connections {
        target: processador

        onCartaoInvalido: {
            console.debug("Oooops! Cartão inválido!");
            timerInfo.adicionarMensagem("Cartão inválido!", "qrc:///erro", 2000);
        }

        onCartaoAtualizado: {
            console.debug("Cartão atualizado!");
            timerInfo.adicionarMensagem("Atualizado!", "qrc:///ok", 2000);
        }

        onNenhumaCompraEfetuada: {
            console.debug("Oops! Nenhuma compra efetuada!");
            timerInfo.adicionarMensagem("Não foi feita nenhuma compra ainda!", "qrc:///ok", 2000);
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
        model: cartaoModel
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
        message: "Deseja mesmo excluir o cartão " + MainScript.cartaoMainSelecionado + "?<br>Todos os históricos de compras e benefícios também serão excluídos!"
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
                    visa.Consultar(MainScript.cartaoMainSelecionado, true);
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
        id: erroConexao;
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
}
