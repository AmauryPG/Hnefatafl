#include <QtWidgets>
#include "mainwindow.h"


MainWindow::MainWindow()
{
	setWindowTitle("Hnefatafl");  
	  

	for (int x = 0; x < 13; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			m_etatJeu[x][y] = VIDE;
		}
	}

	//coin
	m_etatJeu[0][0] = CASE_ROI;
	m_etatJeu[12][0] = CASE_ROI;
	m_etatJeu[0][12] = CASE_ROI;
	m_etatJeu[12][12] = CASE_ROI;

	//central
	m_etatJeu[6][6] = CASE_BLOQUE;

	m_etatJeu[2][2] = PIECE_BLANC;
	m_etatJeu[2][4] = PIECE_ROI;
	m_etatJeu[2][3] = PIECE_NOIR;

	for (int x = 0; x < 13; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			m_tableJeu[x][y] = new QLabel(this);
			m_pixmap = new QPixmap(PATH + "case_0" + QString::number(m_etatJeu[x][y]) + ".png");
			m_tableJeu[x][y]->setPixmap(*m_pixmap);
			m_tableJeu[x][y]->setGeometry(QRect(QPoint(x * 46, y * 46), QSize(49,49))); 
		}
	}  

	m_curseur = new QLabel(this);
	m_pixmap = new QPixmap(CURSEUR);
	m_curseur->setPixmap(*m_pixmap);
	m_curseur->setGeometry(QRect(QPoint(m_x * 46, m_y * 46), QSize(49, 49)));

}

MainWindow::~MainWindow()
{  
	delete m_pixmap;  

	//effacer le tableau
	for (int x = 0; x < 13; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			delete m_tableJeu[x][y];
		}
	}
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{ 
	switch (event->key())
	{
	case Qt::Key_W:
		if(m_y >= 1)
			m_y--;
		break;
	case Qt::Key_A:
		if(m_x >= 1)
			m_x--;
		break;
	case Qt::Key_S:
		if(m_y < 12)
			m_y++;
		break;
	case Qt::Key_D:
		if (m_x < 12)
			m_x++;
		break;
	//le enter offert par qt ne marcher pas. Peut etre a cause de machine ou pas.
	case 16777220: 
		if (!m_pick && m_etatJeu[m_x][m_y] > 3)
		{ 
			m_XPick = m_x;
			m_YPick = m_y;
			m_pick = true;
		}
		else if (m_pick && m_etatJeu[m_x][m_y] < 4)
		{  
			temp = m_etatJeu[m_x][m_y];
			m_etatJeu[m_x][m_y] = m_etatJeu[m_XPick][m_YPick];
			m_etatJeu[m_XPick][m_YPick] = temp; 

			m_pixmap = new QPixmap(PATH + "case_0" + QString::number(m_etatJeu[m_x][m_y]) + ".png");
			m_tableJeu[m_x][m_y]->setPixmap(*m_pixmap);
			m_tableJeu[m_x][m_y]->setGeometry(QRect(QPoint(m_x * 46, m_y * 46), QSize(49, 49)));

			m_pixmap = new QPixmap(PATH + "case_0" + QString::number(m_etatJeu[m_XPick][m_YPick]) + ".png");
			m_tableJeu[m_XPick][m_YPick]->setPixmap(*m_pixmap);
			m_tableJeu[m_XPick][m_YPick]->setGeometry(QRect(QPoint(m_XPick * 46, m_YPick * 46), QSize(49, 49)));

			m_pick = false;
		}
		break;
	} 
	m_curseur->setGeometry(QRect(QPoint(m_x * 46, m_y * 46), QSize(49, 49)));
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Q)
	{
		cout << "ll" << endl;
	}
}