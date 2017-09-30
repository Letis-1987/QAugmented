import QtQuick 2.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0

Entity {
    components: [
        CuboidMesh {
            id: mesh
            xExtent: 2
            yExtent: 2
            zExtent: 2
        },
        PhongMaterial {
            diffuse: "green"
            ambient: "green"
            specular: "green"
        },
        Transform {
//            property matrix4x4 mat: Qt.matrix4x4(1, 0, 0, 0,
//                                                 0, 1, 0, 0,
//                                                 0, 0, 1, 0,
//                                                 0, 0, 0, 1)
//            onMatChanged: matrix = mat
            id: objectTransform
            objectName: "objectTransform"

//            Behavior on matrix {

//                NumberAnimation {
//                    duration: 200
//                }
//            }

//            NumberAnimation {
//                target: objectTransform
//                property: "rotationY"
//                from: 0
//                to: 360
//                duration: 5000
//                loops: Animation.Infinite
//                running: true
//            }
//            NumberAnimation {
//                target: objectTransform
//                property: "rotationZ"
//                from: 0
//                to: 360
//                duration: 4000
//                loops: Animation.Infinite
//                running: true
//            }
        }
    ]
}
