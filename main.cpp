#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{ 

	QApplication app(argc, argv);

	MainWindow gui;
	gui.show();

	/*
	Jeu *p_jeu;
	Jeu jeu;
	p_jeu = &jeu;
	BoatSetupPage page(p_jeu, NULL);
	page.show();
	*/
	return app.exec();
}