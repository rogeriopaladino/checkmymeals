// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {    

    property int quadrados: 0
    property int quadradoAtual: 0

    onQuadradosChanged:
    {
        if (quadrados > 0)
        {
            for (var i = 0; i < quadrados; i++)
            {
                var comp = Qt.createComponent("Quadradinho.qml");
                var obj = comp.createObject(quadrados);
            }
        }
        else
            console.debug("Impossivel criar quantidade negativa de quadrados!");
    }

    onQuadradoAtualChanged:
    {
        if (quadradoAtual >= 0 && quadradoAtual < quadrados.children.length)
        {
            for (var i = 0; i < quadrados.children.length; i++)
            {
                if (i == quadradoAtual)
                    quadrados.children[i].ativado();
                else
                    quadrados.children[i].desativado();
            }
        }
    }

    function limpar()
    {
        for (var i = 0; i < quadrados.children.length; i++)
            quadrados.childrent[i].destroy();
    }

    Flow
    {
        id: quadrados
        anchors.fill: parent
        spacing: 2
    }
}
