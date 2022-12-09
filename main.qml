import QtQuick
import untitled 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyCustomComponent {}

    MyButton {
        text: "https://www.google.fr/"
    }

    Loader {
        source: "qrc:///temp/test.txt"
    }

    Loader {
        source: "qrc:/temp/test.txt"
    }
}
