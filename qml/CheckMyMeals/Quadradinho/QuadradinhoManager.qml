// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {    
    id: root
    width: quadradosFlow.width; height: 10;

    property int quadrados: -1
    property int quadradoAtual: -1

    onQuadradosChanged:
    {
        if (quadrados > 0)
        {
            for (var i = 0; i < quadrados; i++)
            {
                var comp = Qt.createComponent("Quadradinho.qml");
                var obj = comp.createObject(quadradosFlow);
            }
        }
        else
            console.debug("Impossivel criar quantidade negativa de quadrados!");
    }

    onQuadradoAtualChanged:
    {
        if (quadradoAtual >= 0 && quadradoAtual < quadradosFlow.children.length)
        {
            for (var i = 0; i < quadradosFlow.children.length; i++)
            {
                if (i == quadradoAtual)
                    quadradosFlow.children[i].ativado();
                else
                    quadradosFlow.children[i].desativado();
            }
        }
    }

    function limpar()
    {
        for (var i = 0; i < quadrados.children.length; i++)
            quadradosFlow.childrent[i].destroy();
    }

    Flow
    {
        id: quadradosFlow
        spacing: 2
    }
}
