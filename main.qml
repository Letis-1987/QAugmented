import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Scene3D 2.0
import QtMultimedia 5.9

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("QAugmented")

    Scene3D {
        anchors.fill: parent
        focus: true

        Keys.onPressed: {
            if (event.key === Qt.Key_Space)
                scene.screen.capture();
            if (event.key === Qt.Key_Escape)
            {
                scene.screen.camera.stop();
                Qt.exit(0);
            }
        }

        Scene {
            id: scene
            sceneWidth: root.width
            sceneHeight: root.height

        }
    }
}
