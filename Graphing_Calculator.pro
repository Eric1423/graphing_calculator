CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"....\SFML-2.0\lib" #change this
#LIBS += -L"....\SFML-2.0\bin" #change this

#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "....\SFML-2.0\include" #change this
#DEPENDPATH  += "....\SFML-2.0\include" #change this

#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"




SOURCES += \
    main.cpp \
    sidebar.cpp \
    system.cpp \
    circle.cpp \
    points.cpp \
    brackets.cpp \
    number.cpp \
    operator.cpp \
    rpn.cpp \
    shunting_yard.cpp \
    token.cpp \
    tokenizer.cpp \
    varialbe.cpp \
    animate.cpp

HEADERS += \
    constants.h \
    sidebar.h \
    system.h \
    circle.h \
    points.h \
    brackets.h \
    constant.h \
    number.h \
    operator.h \
    rpn.h \
    shunting_yard.h \
    token.h \
    tokenizer.h \
    varialbe.h \
    animate.h \
    MyStack.h \
    MyQueue.h \
    node.h \
    linked_list_functions.h
