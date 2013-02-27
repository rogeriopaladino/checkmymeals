// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root
    height: (root.modelo == null ? opcoes.height + 10 : lstItens.height)

    property color corBorda: "blue"
    property color corFundo: "red"
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

            Rectangle {
                width: parent.width; height: txtCaption.height
                border { color: root.corBorda; width: (root.mostrarBorda ? 1 : 0) }
                color: root.corFundo

                Rectangle {
                    width: parent.width * (root.totalItens > 0 ? valorProp / (root.modelo == null ? root.totalItens : lstItens.count) : 1); height: parent.height
                    color: root.corFundoOpcao
                }
            }

            Text {
                id: txtCaption
                text: textoProp
                width: parent.width;
                wrapMode: Text.WordWrap
                color: root.corFonte
                font { pixelSize: 16 }
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
    }
}
