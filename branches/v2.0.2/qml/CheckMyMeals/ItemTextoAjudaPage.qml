import QtQuick 1.1
import "cores.js" as Cores

Text {
    id: txt
    width: parent.width
    color: Cores.COR_TEXTO
    wrapMode: "WordWrap"

    property alias texto: txt.text
}
