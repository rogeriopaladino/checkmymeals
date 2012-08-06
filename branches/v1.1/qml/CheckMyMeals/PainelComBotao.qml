// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1

import "main.js" as MainScript

PainelInformativo {
    id: root

    signal cancelar()
    signal fechar()

    Connections {
        target: visa

        onIniciandoConsulta: {
            //console.debug("Iniciando a consulta..." + cartao);
            root.mostrar(true);
            //processando.open();
        }

        /*onIniciandoConsultaLote: {
            //processando.open();
            root.mostrar(true);
        }*/

        /*onConsultaLoteFinalizada: {
            //processando.close();
            //painelInfo.mostrar(fasle);
        }*/

        //a consulta foi finalizada e o objeto processador já foi conectado aos modelos
        onConsultaFinalizada: {
            //processando.close();
            btn.text = "Fechar";
        }

        onConsultaCancelada: {
            //processando.close();
            timerInfo.adicionarMensagem("Consulta cancelada!", "qrc:///atencao", 2000);
        }

        onErroConexao: {
            //processando.close();
            root.mostrar(false);
        }
    }

    Connections {
        target: processador

        onCartaoInvalido: {
            root.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao) + " inválido!");
        }

        onSistemaForaDoAr: {
            root.mostrar(false);
        }

        onCartaoAtualizado: {
            root.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao) + " atualizado!");
        }

        onNenhumaCompraEfetuada: {
            root.adicionarMensagem("Cartão " + MainScript.formatNumeroCartao(cartao)  + " não tem novas compras!");
        }
    }

    ButtonRow {
        width: parent.width
        anchors {  top: lista.bottom; horizontalCenter: parent.horizontalCenter }

        Button {
            id: btn
            text: "Cancelar"
            onClicked: {
                if (btn.text == "Cancelar") {
                    btn.text = "Fechar";
                    root.cancelar();
                } else {
                    root.fechar();
                    root.limpar();
                    btn.text = "Cancelar";
                    root.mostrar(false);
                }
            }
        }
    }
}
