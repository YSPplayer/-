/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#pragma once
#include "gamedeckwindow.h"
namespace GameClient { 
	class GameClientDeckWindow : public GameDeckWindow {
		Q_OBJECT  
	public:
		void BindEvent();
		GameClientDeckWindow(QWidget *parent = nullptr);
		~GameClientDeckWindow();
	private slots:
		void ScrollingChangeLoadCard();
	};
}