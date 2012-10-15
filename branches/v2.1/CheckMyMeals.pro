# Add more folders to ship with the application, here
folder_01.source = qml/CheckMyMeals
folder_01.target = qml
#DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

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

VERSION = 2.1.0

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

CONFIG += qt-components

#DEFINES += CORE_LIBRARY


TIPO_VERSAO +=

!contains(TIPO_VERSAO, VERSAO_FREE) {
    symbian:TARGET.UID3 = 0x2004b861
    message("Versão completa!")
} else {
    symbian:TARGET.UID3 = 0x2004b862
    message("Versão free!")
    DEFINES += VERSAO_FREE
}

symbian {
    TARGET.CAPABILITY += NetworkServices ReadUserData

    ICON = CheckMyMeals.svg

    vendorinfo += "%{\"RPaladino\"}" ":\"RPaladino-BR\""

    my_deployment.pkg_prerules += vendorinfo
    my_deployment.pkg_prerules += \
        "; Dependency to Symbian Qt Quick components" \
        "(0x200346DE), 1, 1, 0, {\"Qt Quick components\"}"

    DEFINES += VERSION=\"$$VERSION\"   

    contains(TIPO_VERSAO, VERSAO_FREE) {
        DEPLOYMENT.display_name += CheckMyMeals FREE
        TARGET = CheckMyMeals_free
    } else {
        DEPLOYMENT.display_name += CheckMyMeals
        TARGET = CheckMyMeals
    }

    DEPLOYMENT += my_deployment
}

win32 {
    DEFINES += VERSION=\\\"$$VERSION\\\"
}

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    cvisa.cpp \
    cestudos.cpp \
    ccartaomodel.cpp \
    ccartaoitem.cpp \
    ccompramodel.cpp \
    ccompraitem.cpp \
    cprocessador.cpp \
    cartaoproxy.cpp \
    cutil.cpp

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
    cartaoproxy.h \
    cutil.h

RESOURCES += \
    res.qrc \
    qml.qrc



































































