/*
创建人：神数不神
创建日期：2024-6-10
无修正
*/
#include "gameclientwindow.h"
namespace GameClient {
	GameClientWindow::GameClientWindow(GameWindow *parent):GameWindow(parent) {

	
	} 

	GameClientWindow::~GameClientWindow() {
		
	}

	void GameClientWindow::BindEvent() {
		//卡组编辑界面右侧鼠标滚轮移动
		connect(cardSearchScrollArea.scrollArea, &CScrollArea::scrollingUp, this, &GameClientWindow::ScrollingChangeLoadCard);	
	}

	/// <summary>
	/// 滚轮移动时加载新的卡片
	/// </summary>
	void GameClientWindow::ScrollingChangeLoadCard() {
		
	}
}