import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

ApplicationWindow {
    width: 640
    height: 620
    visible: true
    title: qsTr("Location Manager")


//    Image {
//        id: name
//        source: "qrc:/Back.jpg"
//        anchors.fill: parent
//    }



    LocationManager {
        anchors.centerIn: parent
        anchors.fill: parent

    }


}














