// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root
    height: (root.modelo == null ? opcoes.height + 10 : 0)

    property color corBorda: "blue"
    property color corFundo: "red"
    property color corFundoPar: "gray"
    property color corFundoOpcao : "gray"
    property color corFonte: "white"
    property bool mostrarBorda: true

    property variant opcoesAdicionadas: null
    property int totalItens: 0

    property variant modelo: null

    onModeloChanged: {
        if (root.modelo != null)
        {
            lstItens.delegate = rectComp;
        }
    }

    Component {
        id: rectComp

        Item {
            width: parent.width; height: childrenRect.height
            property string textoProp: (root.modelo == null ? "<opcao>" : nomeRole)
            property int valorProp: (root.modelo == null ? 0 : valorRole)
            property int valorTotalProp : (root.modelo == null ? 0 : totalRole);
            property double valorTotalVisitaProp : (root.modelo == null ? 0 : valorTotalVisitaRole)

            property int indice : (root.modelo == null ? 0 : index)

            Rectangle {
                width: parent.width; height: txtCaption.height
                border { color: root.corBorda; width: (root.mostrarBorda ? 1 : 0) }
                color: (indice % 2 == 0 ? root.corFundoPar : root.corFundo)

                Rectangle {
                    width: parent.width * (valorTotalProp > 0 ? valorProp / valorTotalProp : 1); height: parent.height
                    color: root.corFundoOpcao
                }                
            }

            Text {
                id: txtCaption
                text: textoProp
                width: parent.width - 55;
                wrapMode: Text.WordWrap
                color: root.corFonte
                font { pixelSize: 15 }
            }

            Row {
                anchors.right: parent.right

                Text {
                    text: valorProp
                    width: 35
                    color: root.corFonte
                    font { pixelSize: 15 }
                }

                Text {
                    text: "R$ " + valorTotalVisitaProp.toFixed(2)
                    width: 100
                    color: root.corFonte
                    font { pixelSize: 15 }
                }
            }
        }
    }

    function adicionarOpcao(nome, valor)
    {
        if (root.modelo == null)
        {
            if (root.opcoesAdicionadas == null)
                root.opcoesAdicionadas = new Array();
            var obj = rectComp.createObject(opcoes);
            obj.texto = nome;
            obj.valor = valor;
            root.totalItens += valor;
            root.opcoesAdicionadas.push(obj);
        }
        else
        {

        }
    }

    Column {
        id: opcoes
        width: parent.width
        spacing: 4
        visible: root.modelo == null
    }

    ListView {
        id: lstItens
        anchors.fill: parent
        visible: root.modelo != null
        model: root.modelo
        spacing: 2
        clip: true
    }
}
