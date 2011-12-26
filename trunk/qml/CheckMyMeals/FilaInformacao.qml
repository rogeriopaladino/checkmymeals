import QtQuick 1.0
import com.nokia.extras 1.1
import "main.js" as MainScript

Item {
    function adicionarMensagem(mensagem, icone, intervalo) {
        MainScript.mensagens.push([mensagem, icone, intervalo]);
        timerInfo.restart();
    }

    Timer {
        id: timerInfo
        running: false
        triggeredOnStart: true

        onTriggered: {            
            var item = MainScript.mensagens.shift();
            info.text = item[0];
            info.iconSource = item[1];
            info.timeout = item[2];
            info.open();
            if (MainScript.mensagens.length > 0)
                timerInfo.interval = item[2] + 300;
            else
                timerInfo.stop();
        }

        onRunningChanged: {
            if (!timerInfo.running) {
                if (MainScript.mensagens.length > 0) {
                    console.debug("Ainda tem!");
                    timerInfo.restart();
                }
            }
        }
    }

    InfoBanner {
        id: info
    }
}
