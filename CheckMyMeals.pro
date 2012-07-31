# Add more folders to ship with the application, here
folder_01.source = qml/CheckMyMeals
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0x2004b861

QT += network
QT += xml
QT += xmlpatterns
QT += sql

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian {
    TARGET.CAPABILITY += NetworkServices

    my_deployment.pkg_prerules += vendorinfo

    DEPLOYMENT += my_deployment

    vendorinfo += "%{\"RPaladino\"}" ":\"RPaladino-BR\""
}
# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

CONFIG += qtquickcomponents

#DEFINES += CORE_LIBRARY

#Symbian {
    ICON = CheckMyMeals.svg
#}

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    cvisa.cpp \
    cestudos.cpp \
    ccartaomodel.cpp \
    ccartaoitem.cpp \
    ccompramodel.cpp \
    ccompraitem.cpp \
    cprocessador.cpp \
    cartaoproxy.cpp

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

HEADERS += \
    cvisa.h \
    cestudos.h \
    ccartaomodel.h \
    ccartaoitem.h \
    ccompramodel.h \
    ccompraitem.h \
    cprocessador.h \
    cartaoproxy.h

OTHER_FILES += \    
    qml/CheckMyMeals/main.js \
    qml/CheckMyMeals/cores.js

RESOURCES += \
    res.qrc


































































