import QtQuick 2.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick.Scene2D 2.9
import QtMultimedia 5.9 as Mult

Entity {
    id: screen
    objectName: "screen"
    property real aspectRatio: videoCamera.viewfinder.resolution.width / videoCamera.viewfinder.resolution.height
    property var referenceVector
    property alias screenWidth: mesh.width
    property alias screenHeight: mesh.height
    property alias camera: videoCamera

    signal capture()

    components: [
    PlaneMesh {
        id: mesh
    },
    TextureMaterial {
        texture: videoTexture
    },
    Transform {
        rotationX: 270
        translation: Qt.vector3d(0, 0, referenceVector.z + 580)
    },
    ObjectPicker{}]

    Scene2D {
        output: RenderTargetOutput {
//            attachmentPoint: RenderTargetOutput.Color0
            texture: Texture2D {
                id: videoTexture
                width: mesh.width
                height: mesh.height
                format: Texture.RGBA8_UNorm
//                generateMipMaps: true
//                magnificationFilter: Texture.Linear
//                minificationFilter: Texture.LinearMipMapLinear
//                wrapMode {
//                    x: WrapMode.ClampToEdge
//                    y: WrapMode.ClampToEdge
//                }
            }
        }
        entities: [screen]

//        Rectangle {
//            id: videoCamera
//            width: 640
//            height: 480
//        }
        Mult.VideoOutput {
            width: mesh.width
            height: mesh.height
            source: videoCamera

            Mult.Camera {
                id: videoCamera
                objectName: "videoCamera"
            }

//            Mult.MediaPlayer {
//                id: videoCamera
//                objectName: "videoCamera"
//                source: "../AugReal/Samples/video.avi"
//            }
        }
    }
}
