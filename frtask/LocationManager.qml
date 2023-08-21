import QtQuick
import QtQuick.Controls
import QtQuick.Layouts



ListView{
    id:listView
    spacing: 12
    clip: true
    model: LocationManagerModel
    delegate:
        Rectangle {
        color: "#00ff00"
        width: listView.width
        height: 200
        radius: 10
        opacity: 0.9
        GridLayout {
            anchors.margins:5
            anchors.centerIn: parent
            anchors.fill: parent
            columns: 4
            rowSpacing: 1
            columnSpacing: 1
            Rectangle {
                Layout.columnSpan: 4
                Layout.preferredHeight: 10
                Layout.fillWidth: true
                Layout.fillHeight: true
                Image {
                    anchors.fill: parent
                    source: model.picture
                }
            }
            Rectangle {
                color: "transparent"
                Layout.preferredHeight: 1.75
                Layout.fillWidth: true
                Layout.preferredWidth: 0.35
                Layout.fillHeight: true

                Rectangle {
                    anchors.centerIn: parent
                    width: 15
                    height: 15
                    radius: 7.5
                    color: model.colour
                }
            }

            Rectangle {
                color: "transparent"
                Layout.preferredHeight: 2
                Layout.fillWidth: true
                Layout.preferredWidth: 10
                Layout.fillHeight: true
                Text {
                    font.bold: true
                    font.pixelSize: 20
                    text: model.name
                }
            }
            Rectangle {
                color: "transparent"
                Layout.preferredHeight: 2
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                Layout.fillHeight: true
                ColumnLayout {
                    anchors.fill: parent
                    ToolButton {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        icon.source: "qrc:/edit.png"
                        icon.width: 300
                        icon.height: 300
                        onClicked: {
                            LocationManagerModel.editClicked(model.name, "edit")
                        }
                    }
                }
            }
            Rectangle {
                color: "transparent"
                Layout.preferredHeight: 2
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                Layout.fillHeight: true
                ColumnLayout {
                    anchors.fill: parent
                    ToolButton{
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        icon.source: "qrc:/delete.png"
                        icon.width: parent.width
                        icon.height: parent.height
                        onClicked: {
                            LocationManagerModel.deleteClicked(model.name, "delete")

                        }
                    }
                }
            }
            Rectangle {
                color: "transparent"
                Layout.preferredHeight: 1.75
                Layout.fillWidth: true
                Layout.preferredWidth: 0.35
                Layout.fillHeight: true

            }
            Rectangle {
                Layout.columnSpan: 3
                color: "transparent"
                Layout.preferredHeight: 2
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 12
                Text {
                    font.pixelSize: 15
                    text: model.loc
                }
            }
            Rectangle {
                color: "transparent"
                Layout.preferredHeight: 1.75
                Layout.fillWidth: true
                Layout.preferredWidth: 0.35
                Layout.fillHeight: true

            }
            Rectangle {
                Layout.columnSpan: 3
                color: "transparent"
                Layout.preferredHeight: 2
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.preferredWidth: 12
                Text {
                    font.pixelSize: 15
                    text: model.mercator.x+", "+model.mercator.y
                }
            }
        }
    }
}
