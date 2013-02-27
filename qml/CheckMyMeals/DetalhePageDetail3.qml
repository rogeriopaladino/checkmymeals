// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

import "cores.js" as Cores

Rectangle {
    color: Cores.COR_FUNDO

    GroupBox {
        anchors.fill: parent
        titulo: "Relação de utilizações do cartão"
        corBorda: Cores.COR_INICIAL_BACKGROUND
        visible: !util.versaoFree

        GraphOpcoes {
            id: grphOpcoes
            width: parent.width; height: 200;
            modelo: modeloRelacaoUtilizacao
        }

        Component.onCompleted: {
            /*grphOpcoes.adicionarOpcao("opa", 100);
            grphOpcoes.adicionarOpcao("teste", 100);
            grphOpcoes.adicionarOpcao("aligatô", 300);*/
        }
    }
}
