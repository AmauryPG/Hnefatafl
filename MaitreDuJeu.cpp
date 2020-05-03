#include "MaitreDuJeu.h"

//x et y sont les nouvelles coordonner de la piece
int capture(int x, int y, int m_etatJeu[11][11])
{
	int couleurPieceBouger = m_etatJeu[x][y];
	int couleurPieceOpposee;

	//on verfifie pour la piece roi
	if (couleurPieceBouger == PIECE_NOIR)
	{
		int isRoiMort = VIDE;

		if (m_etatJeu[x + 1][y] == PIECE_ROI)
		{
			isRoiMort = captureRoi(x + 1, y, m_etatJeu);
		}
		else if (m_etatJeu[x - 1][y] == PIECE_ROI)
		{
			isRoiMort = captureRoi(x - 1, y, m_etatJeu);
		}else if (m_etatJeu[x][y + 1] == PIECE_ROI)
		{
			isRoiMort = captureRoi(x, y + 1, m_etatJeu);
		}
		else if (m_etatJeu[x][y - 1] == PIECE_ROI)
		{
			isRoiMort = captureRoi(x, y - 1, m_etatJeu);
		}

		//au cas qu'on perd le jeu
		if (isRoiMort == DEFAIT_BLANC)
		{
			return DEFAIT_BLANC;
		}
	}
	else if (couleurPieceBouger == PIECE_ROI)
	{ 
		if (victoireRoi(x, y) == DEFAIT_NOIR)
		{
			return DEFAIT_NOIR;
		}
	}


	//on verifie pour les autres pieces
	if (couleurPieceBouger == PIECE_BLANC || couleurPieceBouger == PIECE_ROI)
	{ 
		couleurPieceOpposee = PIECE_NOIR;
	}
	else
	{
		couleurPieceOpposee = PIECE_BLANC;
	}

	//on verifie les conditions de capture de la piece
	if (x + 2 < 11 && m_etatJeu[x + 1][y] == couleurPieceOpposee && m_etatJeu[x + 2][y] != couleurPieceOpposee && m_etatJeu[x + 2][y] != VIDE)
	{
		//piece est capturer
		return DROIT;
	}
	else if (x - 2 >= 0 && m_etatJeu[x - 1][y] == couleurPieceOpposee && m_etatJeu[x - 2][y] != couleurPieceOpposee && m_etatJeu[x - 2][y] != VIDE)
	{
		//piece est capturer
		return GAUCHE;
	}
	else if (y + 2 < 11 && m_etatJeu[x][y + 1] == couleurPieceOpposee && m_etatJeu[x][y + 2] != couleurPieceOpposee && m_etatJeu[x][y + 2] != VIDE)
	{
		//piece est capturer
		return BAS;
	}
	else if (y - 2 >= 0 && m_etatJeu[x][y - 1] == couleurPieceOpposee && m_etatJeu[x][y - 2] != couleurPieceOpposee && m_etatJeu[x][y - 2] != VIDE)
	{
		//piece est capturer
		return HAUT;
	}
	return VIDE;
}

int captureRoi(int x, int y, int m_etatJeu[11][11])
{
	//on regarde si le roi est entoure de pieces noir
	if (m_etatJeu[x + 1][y] == PIECE_NOIR && m_etatJeu[x - 1][y] == PIECE_NOIR && m_etatJeu[x][y + 1] == PIECE_NOIR && m_etatJeu[x][y - 1] == PIECE_NOIR)
	{
		return DEFAIT_BLANC;
	}
	else
	{
		return VIDE;
	}
}

int victoireRoi(int x, int y)
{
	if ((x == 0 && y == 0) || (x == 0 && y == 10) || (x == 10 && y == 0) || (x == 10 && y == 10))
	{
		return DEFAIT_NOIR;
	}
	else
	{
		return VIDE;
	}
}

bool mouvementLegal(int x, int y, int nx, int ny, int m_etatJeu[11][11])
{
	if (m_etatJeu[nx][ny] == VIDE && (x == nx || y == ny))
	{
		m_etatJeu[nx][ny] = m_etatJeu[x][y];
		m_etatJeu[x][y] = VIDE; 
		return true;
	}
	else
	{
		return false;
	}
}
