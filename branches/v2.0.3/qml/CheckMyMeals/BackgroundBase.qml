// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "cores.js" as Cores

Rectangle {
    id: root
    color: "black"

    function corAleatoria() {
        var r = Math.round(Math.random(Date.now) * Cores.cores.length - 1);
        r = (r < 0 ? 0 : r);
        root.toColor = Cores.cores[r];
        root.corAleatoriaEscolhida = Cores.cores[r];
    }

    function colocarCor(cor) {
        root.toColor = cor;
        root.corAleatoriaEscolhida = cor;
    }

    property int margemEsquerda: 0
    property int margemSuperior: 0
    property int margemInferior: 0
    property int margemDireita: 0

    property string corAleatoriaEscolhida : Cores.COR_INICIAL_BACKGROUND

    property string toColor

    onToColorChanged: {
        root.color = root.toColor;
    }

    Behavior on color {
        ColorAnimation { duration: 750 }
    }
}
