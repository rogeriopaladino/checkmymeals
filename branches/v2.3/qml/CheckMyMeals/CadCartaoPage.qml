import QtQuick 1.1
import com.nokia.symbian 1.1
import com.nokia.extras 1.1
import "cores.js" as Cores
import "main.js" as MainScript

PageBase {
    id: page
    mostrarAbertura: true
    infoHeader: "Cadastro de cartão"
    tituloAbertura: "Cadastro de cartão"
    descricaoAbertura: "Cadastre novos cartões!"
    tools: ToolBarLayout {
        ToolButton {
            iconSource: "toolbar-back"
            onClicked: {
                page.pageStack.pop();
            }
        }

        ToolButton {
            id: btnCad
            iconSource: "qrc:///toolbar_ok"
            onClicked: {
                if (txtNumero.acceptableInput) {
                    page.ok();
                    page.pageStack.pop();
                } else {
                    info.adicionarMensagem("Número de cartão inválido!", "qrc:///erro", 1500);
                }
            }
        }
    }

    signal ok();

    onVisibleChanged: {
    }

    property alias numero : txtNumero.text
    property alias descricao: txtDescricao.text

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

        TextField {
            id: txtNumero
            width: page.width * 0.70; height: 35
            font.pixelSize: 20
            inputMask: '9999-9999-9999-9999'
            maximumLength: 16
            placeholderText: "Número"
            onFocusChanged: {
                if (txtNumero.focus) {
                    txtNumero.cursorPosition = 0;
                }
            }
        }

        TextField {
            id: txtDescricao
            width: parent.width; height: 35;
            maximumLength: 35
            font.pixelSize: 20
            placeholderText: "Descrição"
        }
    }
}
