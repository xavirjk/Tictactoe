import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
Window {
    visible: true
    minimumWidth: 640
    minimumHeight: 480
    title: qsTr("TicTacToe")
    Component.onCompleted: contentFrame.replace("qrc:/Views/main.qml");
    StackView {
        id: contentFrame
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: parent.left
        }
    }
}
