#pragma once
  
#define PIECE_BLANC 1
#define PIECE_NOIR  2
#define PIECE_ROI   3
#define VIDE        4

#define GAUCHE       0
#define DROIT        1
#define HAUT         2
#define BAS			 3
#define DEFAIT_BLANC 5
#define DEFAIT_NOIR  6

bool mouvementLegal(int x, int y, int nx, int ny, int m_etatJeu[11][11]);
int capture(int x, int y, int m_etatJeu[11][11]);
int captureRoi(int x, int y, int m_etatJeu[11][11]);
int victoireRoi(int x, int y);