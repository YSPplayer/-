/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#include "gameclientwindow.h"
namespace GameClient {
	GameClientWindow::GameClientWindow(GameWindow *parent):GameWindow(parent) {

	
	} 

	GameClientWindow::~GameClientWindow() {
		
	}

	void GameClientWindow::BindEvent() {
		//����༭�����Ҳ��������ƶ�
		connect(cardSearchScrollArea.scrollArea, &CScrollArea::scrollingUp, this, &GameClientWindow::ScrollingChangeLoadCard);	
	}

	/// <summary>
	/// �����ƶ�ʱ�����µĿ�Ƭ
	/// </summary>
	void GameClientWindow::ScrollingChangeLoadCard() {
		
	}
}