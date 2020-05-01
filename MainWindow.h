#pragma once
#include <QMainWindow> 
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
class QTabWidget;
QT_END_NAMESPACE

#include <QWidget> 
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

#include "MaitreDuJeu.h"

const QString PATH = "src/resource/";
const QString CURSEUR = PATH + "curseur.png";

class MainWindow : public QWidget
{
	Q_OBJECT
private:    
	QLabel *m_tableJeu[13][13];
	QLabel *m_background;
	QLabel *m_piecesBlanc[12];
	QLabel *m_pieces;
	QLabel *m_piecesNoir[24];
	QLabel *m_curseur;

	int m_etatJeu[11][11];
	int m_x = 0;
	int m_y = 0;
	bool m_pick = false;
	int m_XPick;
	int m_YPick;
	int temp;

	QPixmap *m_pixmap; 
public:
	MainWindow();
	~MainWindow();

protected:
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
};