import QtQuick 1.1
import com.nokia.symbian 1.1
import com.nokia.extras 1.1
import "cores.js" as Cores
import "main.js" as MainScript
import com.rogerio.definitions 1.0

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
                var msg = "";

                if (!txtNumero.acceptableInput)
                {
                    msg += "Número de cartão inválido.<br>";
                }
                if (selBandeira.selectedIndex == -1)
                {
                    msg += "Bandeira obrigatoria.";
                }

                if (msg == "")
                {
                    page.ok();
                    page.pageStack.pop();
                }
                else
                {
                    info.adicionarMensagem(msg, "qrc:///erro", 1500);
                }
            }
        }
    }

    signal ok();

    onVisibleChanged: {
    }

    property alias numero : txtNumero.text
    property alias descricao: txtDescricao.text
    property int bandeira

    function modoEditar(numero) {
        var infoCartao = cartaoModel.InfoCartao(numero);
        txtNumero.text = infoCartao.numero;
        txtDescricao.text = infoCartao.descricao;
        selBandeira.selectedIndex = selBandeira.retornaIndice(infoCartao.bandeira);
        txtNumero.readOnly = true;
        selBandeira.enabled = false;
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

        SelectionListItem
        {
            width: parent.width
            title: "Bandeira"
            subTitle: (selBandeira.selectedIndex != -1 ? selBandeira.model.get(selBandeira.selectedIndex).name : "")

            onClicked: selBandeira.open()

            SelectionDialog {
                id: selBandeira
                delegate: ListItem {

                    ListItemText{
                        text: name
                    }

                    onClicked: {
                        selBandeira.selectedIndex = index;
                        selBandeira.close();
                    }
                }

                model: ListModel {

                    ListElement {
                        name: "Vale Refeição/Alelo"
                        valor: EnumsDefinitions.Visa
                    }
                    ListElement {
                        name: "Ticket Refeição"
                        valor: EnumsDefinitions.Ticket
                    }
                }

                onSelectedIndexChanged: {
                    page.bandeira = selBandeira.model.get(selectedIndex).valor
                }

                function retornaIndice(valorDoEnum)
                {
                    for (var i = 0; i < selBandeira.model.count; i++)
                    {
                        if (selBandeira.model.get(i).valor == valorDoEnum)
                            return i;
                    }
                    return -1;
                }
            }
        }
    }
}
