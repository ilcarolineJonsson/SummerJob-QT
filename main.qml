import QtQuick 2.12

import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.0
import QtQuick.Extras 1.4
import QtQuick.Shapes 1.11
import QtQuick.Controls.Universal 2.0
import QtQuick.Controls.Imagine 2.3
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Styles 1.4
import QtQml 2.0
//import com.UDP 1.0


Window {
    id: window
    visible: true
    width: 700
    height: 480
    color: "#101629"
    title: qsTr("Dashboard version 1.0")


    CircularGauge {
        id: circularGauge
        anchors.fill: parent
        stepSize: 0
        maximumValue: 240
        style: CircularGaugeStyle {
            minimumValueAngle:-135
            maximumValueAngle: 135
            tickmarkStepSize: 20

        }

        value:udp.measurement

        Behavior on value{
                NumberAnimation{ duration: 3000}
        }
    }

    Button {
        id: button
        y: 397
        text: qsTr("Package 2")
        anchors.horizontalCenterOffset: 281
        autoRepeat: false
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 43
        onClicked: {
            udp.dataUDP();

        }

    }



    Text {
        id: element
        property real speed : udp.round(circularGauge.value);
        width: 121
        height: 48
        color: "#ae0808"
        text: speed
        font.capitalization: Font.Capitalize
        font.strikeout: false
        font.italic: false
        font.bold: true
        fontSizeMode: Text.FixedSize
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Verdana"
        anchors.verticalCenterOffset: 122
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 34
    }

    Button {
        id: button1
        x: 8
        y: 397
        text: qsTr("Package 1")
        anchors.horizontalCenterOffset: -280
        anchors.bottomMargin: 43
        anchors.horizontalCenter: parent.horizontalCenter
        autoRepeat: false
        anchors.bottom: parent.bottom
        onClicked: {
            udp.data2UDP();

        }

    }

    }























/*##^## Designer {
    D{i:3;anchors_height:300;anchors_x:5;anchors_y:0}D{i:5;anchors_height:300;anchors_x:5;anchors_y:0}
}
 ##^##*/
