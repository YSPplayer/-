/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#pragma once
#include "gamewindow.h"
namespace GameClient { 
	class GameClientWindow : public GameWindow {
		Q_OBJECT  
	public:
		void BindEvent();
		GameClientWindow(GameWindow *parent = nullptr);
		~GameClientWindow();
	private slots:
		void ScrollingChangeLoadCard();
	};
}