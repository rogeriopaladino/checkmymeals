// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.symbian 1.1

import "main.js" as MainScript

PainelInformativo {
    id: root

    signal cancelar()
    signal fechar()

    onFechar: {
        root.limpar();
    }

    Connections {
        target: visa

        onIniciandoConsulta: {
            busy.visible = true;
            root.mostrar(true);
        }

        onConsultaCancelada: {
            root.mostrar(false);
            root.fechar();
        }

        onConsultaFinalizada: {
            busy.visible = false;
            btn.text = "Fechar";
        }

        onErroConexao: {
            busy.visible = false;
            root.mostrar(false);
            root.fechar();
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

    Button {
        id: btn
        anchors { left: parent.left; top: lista.bottom; right: parent.right; bottom: parent.bottom; margins: 5 }
        text: "Cancelar"
        onClicked: {
            if (btn.text == "Cancelar") {
                btn.text = "Fechar";
                root.cancelar();
            } else {
                root.fechar();
                btn.text = "Cancelar";
                root.mostrar(false);
            }
        }
    }

    BusyIndicator {
        id: busy
        anchors.centerIn: parent
        running: busy.visible
    }
}
