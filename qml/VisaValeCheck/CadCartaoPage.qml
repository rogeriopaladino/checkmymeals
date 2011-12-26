import QtQuick 1.1
import com.nokia.symbian 1.1
import com.nokia.extras 1.1
import "cores.js" as Cores
import "main.js" as MainScript

Page {
    id: page
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked: {
                page.pageStack.pop().destroy(1000);
            }
        }

        ToolButton {
            id: btnCad
            iconSource: "qrc:///toolbar_ok"
            onClicked: {
                if (validarNumero()) {
                    page.ok();
                    page.pageStack.pop();
                } else {
                    info.adicionarMensagem("Número de cartão inválido!", "qrc:///erro", 1500);
                }
            }
        }
    }

    signal ok();
    signal infoPagina(string local);

    onVisibleChanged: {
        infoPagina("Cadastro de Cartão");
    }

    property alias numero : txtNumero.text
    property alias descricao: txtDescricao.text

    function validarNumero() {
        var a = /[\d]{4}-[\d]{4}-[\d]{4}-[\d]{4}/;
        return a.test(txtNumero.text);
    }

    function modoEditar(numero) {
        var infoCartao = cartaoModel.InfoCartao(numero);
        txtNumero.text = infoCartao.numero;
        txtDescricao.text = infoCartao.descricao;
        txtNumero.readOnly = true;
    }   

    FilaInformacao {
        id: info
    }

    Column {
        id: colMain                
        anchors.centerIn: parent

        Text {
            text: "Número do cartao"
            color: Cores.COR_TEXTO
            font.pixelSize: 20
        }

        Item {
            width: page.width * 0.70; height: 35;
            Rectangle {
                width: parent.width; height: parent.height                
                gradient: Gradient {
                    GradientStop {
                        position: 0.00;
                        color: Cores.COR_FUNDO_DEGRADE_P0;
                    }
                    GradientStop {
                        position: 1.00;
                        color: Cores.COR_FUNDO_DEGRADE_P1;
                    }
                }
                border.color: "blue"
            }

            TextInput {
                id: txtNumero
                width: parent.width; height: parent.height;
                font.pixelSize: 20
                focus: true
                maximumLength: 16
                color: Cores.COR_TEXTO
                inputMask: '9999-9999-9999-9999'
                onFocusChanged: {
                    if (txtNumero.focus) {
                        txtNumero.cursorPosition = 0;
                    }
                }
                onAccepted: {
                    txtNumero.closeSoftwareInputPanel();
                }
            }
        }

        Text {
            text: "Descrição";
            color: Cores.COR_TEXTO
            font.pixelSize: 20
        }

        Item {
            width: page.width * 0.70; height: 35;
            Rectangle {
                width: parent.width; height: parent.height
                gradient: Gradient {
                    GradientStop {
                        position: 0.00;
                        color: "#5aa3e6";
                    }
                    GradientStop {
                        position: 1.00;
                        color: "#63c6f7";
                    }
                }
                border.color: "blue"
            }

            TextInput {
                id: txtDescricao
                width: parent.width; height: parent.height;
                maximumLength: 35
                font.pixelSize: 20
                color: Cores.COR_TEXTO
            }
        }
    }


}
