#############################################################################
# Makefile for building: CheckMyMeals
# Generated by qmake (2.01a) (Qt 4.7.4) on: ter 12. fev 20:03:16 2013
# Project:  CheckMyMeals.pro
# Template: app
# Command: c:\qtsdk\symbian\sdks\symbian3qt474\bin\qmake.exe -spec ..\..\QtSDK\Symbian\SDKs\Symbian3Qt474\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc -o bld.inf CheckMyMeals.pro
#############################################################################

MAKEFILE          = Makefile
QMAKE             = c:\qtsdk\symbian\sdks\symbian3qt474\bin\qmake.exe
DEL_FILE          = del /q 2> NUL
DEL_DIR           = rmdir
CHK_DIR_EXISTS    = if not exist
MKDIR             = mkdir
MOVE              = move
DEBUG_PLATFORMS   = winscw gcce armv5 armv6
RELEASE_PLATFORMS = gcce armv5 armv6
MAKE              = make
SBS               = sbs

DEFINES	 = -DSYMBIAN -DUNICODE -DQT_KEYPAD_NAVIGATION -DQT_SOFTKEYS_ENABLED -DQT_USE_MATH_H_FLOATS -DVERSION="2.1.0" -DQ_COMPONENTS_SYMBIAN -DQT_NO_DEBUG -DQT_DECLARATIVE_LIB -DQT_SQL_LIB -DQT_XMLPATTERNS_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
INCPATH	 =  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include/QtCore"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include/QtNetwork"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include/QtGui"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include/QtXml"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include/QtXmlPatterns"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include/QtSql"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include/QtDeclarative"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/include"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/mkspecs/common/symbian"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/stdapis"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/stdapis/sys"  -I"C:/Repositorio/checkmymeals/qmlapplicationviewer"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/stdapis/stlportv5"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/mw"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/platform/mw"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/platform"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/platform/loc"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/platform/mw/loc"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/platform/loc/sc"  -I"C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/include/platform/mw/loc/sc"  -I"C:/Repositorio/checkmymeals/moc"  -I"C:/Repositorio/checkmymeals"  -I"C:/Repositorio/checkmymeals/rcc"  -I"C:/Repositorio/checkmymeals/ui" 
first: default

all: debug release

default: debug-winscw
qmake:
	$(QMAKE) "C:/Repositorio/checkmymeals/CheckMyMeals.pro"  -spec ..\..\QtSDK\Symbian\SDKs\Symbian3Qt474\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc

bld.inf: C:/Repositorio/checkmymeals/CheckMyMeals.pro
	$(QMAKE) "C:/Repositorio/checkmymeals/CheckMyMeals.pro"  -spec ..\..\QtSDK\Symbian\SDKs\Symbian3Qt474\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc

c:\Repositorio\checkmymeals\CheckMyMeals.loc: 
	$(QMAKE) "C:/Repositorio/checkmymeals/CheckMyMeals.pro"  -spec ..\..\QtSDK\Symbian\SDKs\Symbian3Qt474\mkspecs\symbian-sbsv2 CONFIG+=release -after  OBJECTS_DIR=obj MOC_DIR=moc UI_DIR=ui RCC_DIR=rcc

debug: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1
clean-debug: bld.inf
	$(SBS) reallyclean --toolcheck=off -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1
freeze-debug: bld.inf
	$(SBS) freeze -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1
release: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1
clean-release: bld.inf
	$(SBS) reallyclean --toolcheck=off -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1
freeze-release: bld.inf
	$(SBS) freeze -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1

debug-winscw: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c winscw_udeb.mwccinc
clean-debug-winscw: bld.inf
	$(SBS) reallyclean -c winscw_udeb.mwccinc
freeze-debug-winscw: bld.inf
	$(SBS) freeze -c winscw_udeb.mwccinc
debug-gcce: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c arm.v5.udeb.gcce4_4_1
clean-debug-gcce: bld.inf
	$(SBS) reallyclean -c arm.v5.udeb.gcce4_4_1
freeze-debug-gcce: bld.inf
	$(SBS) freeze -c arm.v5.udeb.gcce4_4_1
debug-armv5: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c armv5_udeb
clean-debug-armv5: bld.inf
	$(SBS) reallyclean -c armv5_udeb
freeze-debug-armv5: bld.inf
	$(SBS) freeze -c armv5_udeb
debug-armv6: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c armv6_udeb
clean-debug-armv6: bld.inf
	$(SBS) reallyclean -c armv6_udeb
freeze-debug-armv6: bld.inf
	$(SBS) freeze -c armv6_udeb
release-gcce: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c arm.v5.urel.gcce4_4_1
clean-release-gcce: bld.inf
	$(SBS) reallyclean -c arm.v5.urel.gcce4_4_1
freeze-release-gcce: bld.inf
	$(SBS) freeze -c arm.v5.urel.gcce4_4_1
release-armv5: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c armv5_urel
clean-release-armv5: bld.inf
	$(SBS) reallyclean -c armv5_urel
freeze-release-armv5: bld.inf
	$(SBS) freeze -c armv5_urel
release-armv6: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c armv6_urel
clean-release-armv6: bld.inf
	$(SBS) reallyclean -c armv6_urel
freeze-release-armv6: bld.inf
	$(SBS) freeze -c armv6_urel
debug-armv5-gcce4.4.1: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c arm.v5.udeb.gcce4_4_1
clean-debug-armv5-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v5.udeb.gcce4_4_1
freeze-debug-armv5-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v5.udeb.gcce4_4_1
release-armv5-gcce4.4.1: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c arm.v5.urel.gcce4_4_1
clean-release-armv5-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v5.urel.gcce4_4_1
freeze-release-armv5-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v5.urel.gcce4_4_1
debug-armv6-gcce4.4.1: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c arm.v6.udeb.gcce4_4_1
clean-debug-armv6-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v6.udeb.gcce4_4_1
freeze-debug-armv6-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v6.udeb.gcce4_4_1
release-armv6-gcce4.4.1: c:\Repositorio\checkmymeals\CheckMyMeals.loc bld.inf
	$(SBS) -c arm.v6.urel.gcce4_4_1
clean-release-armv6-gcce4.4.1: bld.inf
	$(SBS) reallyclean -c arm.v6.urel.gcce4_4_1
freeze-release-armv6-gcce4.4.1: bld.inf
	$(SBS) freeze -c arm.v6.urel.gcce4_4_1

export: bld.inf
	$(SBS) export -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1 -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1

cleanexport: bld.inf
	$(SBS) cleanexport -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1 -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1

freeze: freeze-release

check: first

run:
	call C:/QtSDK/Symbian/SDKs/Symbian3Qt474/epoc32/release/winscw/udeb/CheckMyMeals.exe $(QT_RUN_OPTIONS)

runonphone: sis
	runonphone $(QT_RUN_ON_PHONE_OPTIONS) --sis CheckMyMeals.sis CheckMyMeals.exe $(QT_RUN_OPTIONS)

CheckMyMeals_template.pkg: C:/Repositorio/checkmymeals/CheckMyMeals.pro
	$(MAKE) -f $(MAKEFILE) qmake

CheckMyMeals_installer.pkg: C:/Repositorio/checkmymeals/CheckMyMeals.pro
	$(MAKE) -f $(MAKEFILE) qmake

CheckMyMeals_stub.pkg: C:/Repositorio/checkmymeals/CheckMyMeals.pro
	$(MAKE) -f $(MAKEFILE) qmake

sis: CheckMyMeals_template.pkg
	$(if $(wildcard .make.cache), $(MAKE) -f $(MAKEFILE) ok_sis MAKEFILES=.make.cache , $(if $(QT_SIS_TARGET), $(MAKE) -f $(MAKEFILE) ok_sis , $(MAKE) -f $(MAKEFILE) fail_sis_nocache ) )

ok_sis:
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\createpackage.bat -g $(QT_SIS_OPTIONS) CheckMyMeals_template.pkg $(QT_SIS_TARGET) $(QT_SIS_CERTIFICATE) $(QT_SIS_KEY) $(QT_SIS_PASSPHRASE)

unsigned_sis: CheckMyMeals_template.pkg
	$(if $(wildcard .make.cache), $(MAKE) -f $(MAKEFILE) ok_unsigned_sis MAKEFILES=.make.cache , $(if $(QT_SIS_TARGET), $(MAKE) -f $(MAKEFILE) ok_unsigned_sis , $(MAKE) -f $(MAKEFILE) fail_sis_nocache ) )

ok_unsigned_sis:
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\createpackage.bat -g $(QT_SIS_OPTIONS) -o CheckMyMeals_template.pkg $(QT_SIS_TARGET)

CheckMyMeals.sis:
	$(MAKE) -f $(MAKEFILE) sis

installer_sis: CheckMyMeals_installer.pkg sis
	$(MAKE) -f $(MAKEFILE) ok_installer_sis

ok_installer_sis: CheckMyMeals_installer.pkg
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\createpackage.bat $(QT_SIS_OPTIONS) CheckMyMeals_installer.pkg - $(QT_SIS_CERTIFICATE) $(QT_SIS_KEY) $(QT_SIS_PASSPHRASE)

unsigned_installer_sis: CheckMyMeals_installer.pkg unsigned_sis
	$(MAKE) -f $(MAKEFILE) ok_unsigned_installer_sis

ok_unsigned_installer_sis: CheckMyMeals_installer.pkg
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\createpackage.bat $(QT_SIS_OPTIONS) -o CheckMyMeals_installer.pkg

fail_sis_nocache:
	$(error Project has to be built or QT_SIS_TARGET environment variable has to be set before calling 'SIS' target)

stub_sis: CheckMyMeals_stub.pkg
	$(if $(wildcard .make.cache), $(MAKE) -f $(MAKEFILE) ok_stub_sis MAKEFILES=.make.cache , $(if $(QT_SIS_TARGET), $(MAKE) -f $(MAKEFILE) ok_stub_sis , $(MAKE) -f $(MAKEFILE) fail_sis_nocache ) )

ok_stub_sis:
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\createpackage.bat -s $(QT_SIS_OPTIONS) CheckMyMeals_stub.pkg $(QT_SIS_TARGET) $(QT_SIS_CERTIFICATE) $(QT_SIS_KEY) $(QT_SIS_PASSPHRASE)

deploy: sis
	call CheckMyMeals.sis

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc\moc_qmlapplicationviewer.cpp moc\moc_cvisa.cpp moc\moc_cestudos.cpp moc\moc_ccartaomodel.cpp moc\moc_ccartaoitem.cpp moc\moc_ccompramodel.cpp moc\moc_ccompraitem.cpp moc\moc_cprocessador.cpp moc\moc_cartaoproxy.cpp moc\moc_cutil.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc\moc_qmlapplicationviewer.cpp moc\moc_cvisa.cpp moc\moc_cestudos.cpp moc\moc_ccartaomodel.cpp moc\moc_ccartaoitem.cpp moc\moc_ccompramodel.cpp moc\moc_ccompraitem.cpp moc\moc_cprocessador.cpp moc\moc_cartaoproxy.cpp moc\moc_cutil.cpp
moc\moc_qmlapplicationviewer.cpp: qmlapplicationviewer\qmlapplicationviewer.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\qmlapplicationviewer\qmlapplicationviewer.h -o c:\Repositorio\checkmymeals\moc\moc_qmlapplicationviewer.cpp

moc\moc_cvisa.cpp: cvisa.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\cvisa.h -o c:\Repositorio\checkmymeals\moc\moc_cvisa.cpp

moc\moc_cestudos.cpp: ccompraitem.h \
		ccartaoitem.h \
		cestudos.h \
		cestudos.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\cestudos.h -o c:\Repositorio\checkmymeals\moc\moc_cestudos.cpp

moc\moc_ccartaomodel.cpp: ccartaoitem.h \
		cestudos.h \
		ccompraitem.h \
		ccompramodel.h \
		ccartaomodel.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\ccartaomodel.h -o c:\Repositorio\checkmymeals\moc\moc_ccartaomodel.cpp

moc\moc_ccartaoitem.cpp: cestudos.h \
		ccompraitem.h \
		ccartaoitem.h \
		ccartaoitem.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\ccartaoitem.h -o c:\Repositorio\checkmymeals\moc\moc_ccartaoitem.cpp

moc\moc_ccompramodel.cpp: ccompraitem.h \
		ccompramodel.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\ccompramodel.h -o c:\Repositorio\checkmymeals\moc\moc_ccompramodel.cpp

moc\moc_ccompraitem.cpp: ccompraitem.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\ccompraitem.h -o c:\Repositorio\checkmymeals\moc\moc_ccompraitem.cpp

moc\moc_cprocessador.cpp: cprocessador.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\cprocessador.h -o c:\Repositorio\checkmymeals\moc\moc_cprocessador.cpp

moc\moc_cartaoproxy.cpp: ccartaoitem.h \
		cestudos.h \
		ccompraitem.h \
		cartaoproxy.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\cartaoproxy.h -o c:\Repositorio\checkmymeals\moc\moc_cartaoproxy.cpp

moc\moc_cutil.cpp: cutil.h
	C:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\moc.exe $(DEFINES) $(INCPATH) -DSYMBIAN c:\Repositorio\checkmymeals\cutil.h -o c:\Repositorio\checkmymeals\moc\moc_cutil.cpp

compiler_rcc_make_all: rcc\qrc_res.cpp rcc\qrc_qml.cpp
compiler_rcc_clean:
	-$(DEL_FILE) rcc\qrc_res.cpp rcc\qrc_qml.cpp
rcc\qrc_res.cpp: res.qrc \
		imagens\button_cancel.png \
		imagens\1318450517_champion.png \
		imagens\reload.png \
		imagens\grafico.png \
		imagens\1318852486_gnome-fs-loading-icon.png \
		imagens\dinheiro.png \
		imagens\toolbar-ajuda.png \
		imagens\toolbar-ok.png \
		imagens\toolbar-info.png \
		imagens\attention.png \
		imagens\1318438005_down.png \
		imagens\1318438190_graph.png \
		imagens\question.png \
		imagens\caiu.png \
		imagens\campeao.png \
		imagens\1318450471_price_money_tag.png \
		imagens\calendario.png \
		imagens\fechar.png \
		imagens\1318438438_love.png \
		imagens\1318437820_shopping_cart_ecommerce_webshop.png \
		imagens\1318437885_date_calendar.png \
		imagens\carrinho.png \
		imagens\favorito.png \
		imagens\clean.png \
		imagens\toolbar-new.png \
		imagens\info.png
	c:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\rcc.exe -name res c:\Repositorio\checkmymeals\res.qrc -o c:\Repositorio\checkmymeals\rcc\qrc_res.cpp

rcc\qrc_qml.cpp: qml.qrc \
		qml\CheckMyMeals\DetalhePageDetail1.qml \
		qml\CheckMyMeals\ItemTextoAjudaPage.qml \
		qml\CheckMyMeals\DetalhePage.qml \
		qml\CheckMyMeals\FilaInformacao.qml \
		qml\CheckMyMeals\ItemIconeAjudaPage.qml \
		qml\CheckMyMeals\PainelComBotao.qml \
		qml\CheckMyMeals\ModalDialogBase.qml \
		qml\CheckMyMeals\Background.qml \
		qml\CheckMyMeals\DetalhePageDetail2.qml \
		qml\CheckMyMeals\AboutPage.qml \
		qml\CheckMyMeals\GroupBox.qml \
		qml\CheckMyMeals\MainInfoCartao.qml \
		qml\CheckMyMeals\cores.js \
		qml\CheckMyMeals\MainWindow.qml \
		qml\CheckMyMeals\MainPage.qml \
		qml\CheckMyMeals\ItemMainInfoCartao.qml \
		qml\CheckMyMeals\PageBase.qml \
		qml\CheckMyMeals\AjudaPage.qml \
		qml\CheckMyMeals\CartaoAnimado.qml \
		qml\CheckMyMeals\DetalheInfo.qml \
		qml\CheckMyMeals\BackgroundBase.qml \
		qml\CheckMyMeals\main.js \
		qml\CheckMyMeals\PainelInformativo.qml \
		qml\CheckMyMeals\DetalhePageDetail0.qml \
		qml\CheckMyMeals\InfoText.qml \
		qml\CheckMyMeals\CadCartaoPage.qml
	c:\QtSDK\Symbian\SDKs\Symbian3Qt474\bin\rcc.exe -name qml c:\Repositorio\checkmymeals\qml.qrc -o c:\Repositorio\checkmymeals\rcc\qrc_qml.cpp

compiler_image_collection_make_all: ui\qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) ui\qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

dodistclean:
	-@ if EXIST "c:\Repositorio\checkmymeals\CheckMyMeals_template.pkg" $(DEL_FILE)  "c:\Repositorio\checkmymeals\CheckMyMeals_template.pkg"
	-@ if EXIST "c:\Repositorio\checkmymeals\CheckMyMeals_stub.pkg" $(DEL_FILE)  "c:\Repositorio\checkmymeals\CheckMyMeals_stub.pkg"
	-@ if EXIST "c:\Repositorio\checkmymeals\CheckMyMeals_installer.pkg" $(DEL_FILE)  "c:\Repositorio\checkmymeals\CheckMyMeals_installer.pkg"
	-@ if EXIST "c:\Repositorio\checkmymeals\Makefile" $(DEL_FILE)  "c:\Repositorio\checkmymeals\Makefile"
	-@ if EXIST "c:\Repositorio\checkmymeals\CheckMyMeals_exe.mmp" $(DEL_FILE)  "c:\Repositorio\checkmymeals\CheckMyMeals_exe.mmp"
	-@ if EXIST "c:\Repositorio\checkmymeals\CheckMyMeals_reg.rss" $(DEL_FILE)  "c:\Repositorio\checkmymeals\CheckMyMeals_reg.rss"
	-@ if EXIST "c:\Repositorio\checkmymeals\CheckMyMeals.rss" $(DEL_FILE)  "c:\Repositorio\checkmymeals\CheckMyMeals.rss"
	-@ if EXIST "c:\Repositorio\checkmymeals\CheckMyMeals.loc" $(DEL_FILE)  "c:\Repositorio\checkmymeals\CheckMyMeals.loc"
	-@ if EXIST "c:\Repositorio\checkmymeals\bld.inf" $(DEL_FILE)  "c:\Repositorio\checkmymeals\bld.inf"

distclean: clean dodistclean

clean: bld.inf
	-$(SBS) reallyclean --toolcheck=off -c winscw_udeb.mwccinc -c arm.v5.udeb.gcce4_4_1 -c arm.v6.udeb.gcce4_4_1 -c arm.v5.urel.gcce4_4_1 -c arm.v6.urel.gcce4_4_1


