TEMPLATE = app

QT += qml quick 3dcore 3drender 3dinput 3dlogic 3dextras 3danimation multimedia
CONFIG += c++11

SOURCES += main.cpp \
    FrameInterceptor.cpp \
    QtViewer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    FrameInterceptor.h \
    QtViewer.h

win32 | win64{
    INCLUDEPATH += "D:/opencv-3.2.0MinGW/include/"
    LIBS += "D:/opencv-3.2.0MinGW/x86/mingw/bin/libopencv*.dll"
}

unix{
    INCLUDEPATH += $$PWD/../../../../usr/local/include
    INCLUDEPATH += $$PWD/../AugReal

    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_calib3d
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_core
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_features2d
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_flann
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_highgui
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_imgcodecs
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_imgproc
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_ml
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_objdetect
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_photo
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_shape
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_stitching
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_superres
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_videoio
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_video
    LIBS += -L$$PWD/../../../../usr/local/lib/ -lopencv_videostab
    LIBS += -L$$PWD/../../../../lib64 -lpthread # For multythreading
    LIBS += -L$$PWD/../build-AugReal-Desktop_Qt_5_9_1_GCC_64bit-Release/ -lAugReal
}
