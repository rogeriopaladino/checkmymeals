// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

import "cores.js" as Cores

Rectangle {
    color: Cores.COR_FUNDO

    GraphOpcoes {
        id: grphOpcoes
        anchors.fill: parent
        modelo: modeloRelacaoUtilizacao
        corFundo: Cores.COR_FUNDO
        corFundoPar: Cores.COR_INICIAL_BACKGROUND
        corFundoOpcao: Cores.COR_FUNDO_LISTA_RELACAO
        mostrarBorda: false
    }
}
