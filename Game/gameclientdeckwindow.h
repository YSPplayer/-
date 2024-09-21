/*
创建人：神数不神
创建日期：2024-6-10
无修正
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