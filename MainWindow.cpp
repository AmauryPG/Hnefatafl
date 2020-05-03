#include <QtWidgets>
#include "mainwindow.h"


MainWindow::MainWindow()
{
	setWindowTitle("Hnefatafl");  

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			m_etatJeu[x][y] = VIDE;
		}
	}  

	m_etatJeu[0][3] = PIECE_NOIR;
	m_etatJeu[0][4] = PIECE_NOIR;
	m_etatJeu[0][5] = PIECE_NOIR;
	m_etatJeu[0][6] = PIECE_NOIR;
	m_etatJeu[0][7] = PIECE_NOIR;
	m_etatJeu[1][5] = PIECE_NOIR;

	m_etatJeu[10][3] = PIECE_NOIR;
	m_etatJeu[10][4] = PIECE_NOIR;
	m_etatJeu[10][5] = PIECE_NOIR;
	m_etatJeu[10][6] = PIECE_NOIR;
	m_etatJeu[10][7] = PIECE_NOIR;
	m_etatJeu[9][5] = PIECE_NOIR;

	m_etatJeu[3][0] = PIECE_NOIR;
	m_etatJeu[4][0] = PIECE_NOIR;
	m_etatJeu[5][0] = PIECE_NOIR;
	m_etatJeu[6][0] = PIECE_NOIR;
	m_etatJeu[7][0] = PIECE_NOIR;
	m_etatJeu[5][1] = PIECE_NOIR;

	m_etatJeu[3][10] = PIECE_NOIR;
	m_etatJeu[4][10] = PIECE_NOIR;
	m_etatJeu[5][10] = PIECE_NOIR;
	m_etatJeu[6][10] = PIECE_NOIR;
	m_etatJeu[7][10] = PIECE_NOIR;
	m_etatJeu[5][9] = PIECE_NOIR;


	m_etatJeu[5][5] = PIECE_ROI; 

	m_etatJeu[5][6] = PIECE_BLANC; 
	m_etatJeu[5][4] = PIECE_BLANC;
	
	m_etatJeu[6][5] = PIECE_BLANC;
	m_etatJeu[4][5] = PIECE_BLANC;

	m_etatJeu[4][4] = PIECE_BLANC;
	m_etatJeu[6][6] = PIECE_BLANC;

	m_etatJeu[6][4] = PIECE_BLANC;
	m_etatJeu[4][6] = PIECE_BLANC;

	m_etatJeu[5][3] = PIECE_BLANC;
	m_etatJeu[5][7] = PIECE_BLANC;

	m_etatJeu[3][5] = PIECE_BLANC;
	m_etatJeu[7][5] = PIECE_BLANC;

	m_background = new QLabel(this);
	m_pixmap = new QPixmap(PATH + "background.png");
	m_background->setPixmap(*m_pixmap);
	m_background->setGeometry(QRect(QPoint(0, 0), m_pixmap->size()));

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			m_tableJeu[x][y] = new QLabel(this);
			m_pixmap = new QPixmap(PATH + "case_0" + QString::number(m_etatJeu[x][y]) + ".png");
			m_tableJeu[x][y]->setPixmap(*m_pixmap);
			m_tableJeu[x][y]->setGeometry(QRect(QPoint(x * 44, y * 44), QSize(49, 49)));
		}
	}  

	m_curseur = new QLabel(this);
	m_pixmap = new QPixmap(CURSEUR);
	m_curseur->setPixmap(*m_pixmap);
	m_curseur->setGeometry(QRect(QPoint(m_x * 44, m_y * 44), QSize(49, 49)));

}

MainWindow::~MainWindow()
{  
	delete m_pixmap;  

	//effacer le tablea 
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
		if(m_y < 10)
			m_y++;
		break;
	case Qt::Key_D:
		if (m_x < 10)
			m_x++;
		break;
	//le enter offert par qt ne marcher pas. Peut etre a cause de machine ou pas.
	case 16777220:  
		//prend la piece
		if (!m_pick && m_etatJeu[m_x][m_y] != VIDE)
		{ 
			m_XPick = m_x;
			m_YPick = m_y;
			m_pick = true;
		}
		//relache la piece
		else if (m_pick)
		{ 
			if (mouvementLegal(m_XPick, m_YPick, m_x, m_y, m_etatJeu))
			{
				//changer les images de place
				m_pixmap = new QPixmap(PATH + "case_0" + QString::number(m_etatJeu[m_x][m_y]) + ".png");
				m_tableJeu[m_x][m_y]->setPixmap(*m_pixmap);
				m_tableJeu[m_x][m_y]->setGeometry(QRect(QPoint(m_x * 44, m_y * 44), QSize(49, 49)));

				m_pixmap = new QPixmap(CASE_VIDE);
				m_tableJeu[m_XPick][m_YPick]->setPixmap(*m_pixmap);
				m_tableJeu[m_XPick][m_YPick]->setGeometry(QRect(QPoint(m_XPick * 44, m_YPick * 44), QSize(49, 49)));

				switch (capture(m_x, m_y, m_etatJeu))
				{
				case HAUT:
					m_pixmap = new QPixmap(CASE_VIDE);
					m_tableJeu[m_x][m_y - 1]->setPixmap(*m_pixmap);
					m_tableJeu[m_x][m_y - 1]->setGeometry(QRect(QPoint(m_x * 44, (m_y - 1) * 44), QSize(49, 49)));

					m_etatJeu[m_x][m_y - 1] = VIDE;
					break;
				case BAS:
					m_pixmap = new QPixmap(CASE_VIDE);
					m_tableJeu[m_x][m_y + 1]->setPixmap(*m_pixmap);
					m_tableJeu[m_x][m_y + 1]->setGeometry(QRect(QPoint(m_x * 44, (m_y + 1) * 44), QSize(49, 49)));

					m_etatJeu[m_x][m_y + 1] = VIDE;
					break;
				case DROIT:
					m_pixmap = new QPixmap(CASE_VIDE);
					m_tableJeu[m_x + 1][m_y]->setPixmap(*m_pixmap);
					m_tableJeu[m_x + 1][m_y]->setGeometry(QRect(QPoint((m_x + 1) * 44, m_y * 44), QSize(49, 49)));

					m_etatJeu[m_x + 1][m_y] = VIDE;
					break;
				case GAUCHE:
					m_pixmap = new QPixmap(CASE_VIDE);
					m_tableJeu[m_x - 1][m_y]->setPixmap(*m_pixmap);
					m_tableJeu[m_x - 1][m_y]->setGeometry(QRect(QPoint((m_x - 1) * 44, m_y * 44), QSize(49, 49)));

					m_etatJeu[m_x - 1][m_y] = VIDE;
					break;
				case DEFAIT_NOIR:
					cout << "les noir on perdu" << endl;
					break;
				case DEFAIT_BLANC:
					cout << "les blanc on perdu" << endl;
					break;
				}
			}

			m_pick = false;
		}
		break;
	} 
	m_curseur->setGeometry(QRect(QPoint(m_x * 44, m_y * 44), QSize(49, 49)));
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Q)
	{
		cout << "ll" << endl;
	}
}