# Hnefatafl
Jeu d'échec viking faite avec Qt et c++

Ceci est dans un fichier .pro pour générer le projet
TEMPLATE = vcapp
TARGET = Hnefatafl
SOURCES += src/main.cpp src/MainWindow.cpp
HEADERS += src/MainWindow.h
INCLUDEPATH += ../Hnefatafl
CONFIG += warn_on qt debug windows console
QT += widgets
