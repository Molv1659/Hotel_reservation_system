#-------------------------------------------------
#
# Project created by QtCreator 2018-07-26T14:26:27
#
#-------------------------------------------------

QT       += core gui sql

RC_FILE = hotel1icon.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    hoteldialog.cpp \
    managerdialog.cpp \
    platformdialog.cpp \
    customer.cpp \
    manager.cpp \
    hotel.cpp \
    room.cpp \
    order.cpp \
    customerregestrationdlg.cpp \
    managerregestrationdlg.cpp \
    hotelregestrationdlg.cpp \
    database.cpp \
    checktrial.cpp \
    customerdialog.cpp \
    hotelinfochangedialog.cpp \
    addroomdialog.cpp \
    managerusedorderdialog.cpp \
    customerusedorderdialog.cpp \
    customergradedialog.cpp \
    detailedinfodialog.cpp \
    addorderdialog.cpp \
    customertotaluseddialog.cpp \
    customerinfochangedialog.cpp

HEADERS += \
        mainwindow.h \
    hoteldialog.h \
    managerdialog.h \
    platformdialog.h \
    customer.h \
    manager.h \
    hotel.h \
    room.h \
    order.h \
    customerregestrationdlg.h \
    managerregestrationdlg.h \
    hotelregestrationdlg.h \
    database.h \
    checktrial.h \
    customerdialog.h \
    hotelinfochangedialog.h \
    addroomdialog.h \
    managerusedorderdialog.h \
    customerusedorderdialog.h \
    customergradedialog.h \
    detailedinfodialog.h \
    addorderdialog.h \
    customertotaluseddialog.h \
    customerinfochangedialog.h

FORMS += \
        mainwindow.ui \
    hoteldialog.ui \
    managerdialog.ui \
    platformdialog.ui \
    customerregestrationdlg.ui \
    managerregestrationdlg.ui \
    hotelregestrationdlg.ui \
    customerdialog.ui \
    hotelinfochangedialog.ui \
    addroomdialog.ui \
    managerusedorderdialog.ui \
    customerusedorderdialog.ui \
    customergradedialog.ui \
    detailedinfodialog.ui \
    addorderdialog.ui \
    customertotaluseddialog.ui \
    customerinfochangedialog.ui

RESOURCES += \
    useqss.qrc \
    background.qrc
