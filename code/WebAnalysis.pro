QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    SQLstock.cpp \
    get_url_pix.cpp \
    getstock.cpp \
    main.cpp \
    dialog.cpp\
    confirmation.cpp \
    core.cpp \
    lists.cpp \
    minus.cpp \
    options.cpp \
    plus.cpp \
    purchase.cpp \
    search.cpp \
    switch.cpp \
    terminal.cpp \
    zsmtp.cpp
HEADERS += \
    SQLstock.h \
    confirmation.h \
    core.h \
    core.h \
    dialog.h \
    get_url_pix.h \
    getstock.h \
    lists.h \
    lists.h \
    minus.h \
    minus.h \
    options.h \
    options.h \
    plus.h \
    plus.h \
    purchase.h \
    purchase.h \
    search.h \
    switch.h \
    switch.h \
    terminal.h \
    terminal.h \
    zsmtp.h

FORMS += \
    confirmation.ui \
    core.ui \
    dialog.ui \
    lists.ui \
    minus.ui \
    options.ui \
    plus.ui \
    purchase.ui \
    search.ui \
    switch.ui \
    terminal.ui\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
