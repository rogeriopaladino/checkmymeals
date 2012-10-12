// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle{
    id: root
    width: 10; height: 10;
    color: "black"
    border { color: "blue"; width: 1 }

    Behavior on color {
        ColorAnimation {
            duration: 500
        }
    }

    function ativado()
    {
        root.color = "red";
    }

    function desativado()
    {
        root.color = "black";
    }

}
