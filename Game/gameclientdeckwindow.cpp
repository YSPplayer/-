/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#include "GameClientDeckWindow.h"
namespace GameClient {
	GameClientDeckWindow::GameClientDeckWindow(QWidget*parent):GameDeckWindow(parent) {
	} 

	GameClientDeckWindow::~GameClientDeckWindow() {
	}

	void GameClientDeckWindow::BindEvent() {
		//����༭�����Ҳ��������ƶ�
		connect(cardSearchScrollArea.scrollArea, &CScrollArea::scrollingUp, this, &GameClientDeckWindow::ScrollingChangeLoadCard);	
	}

	/// <summary>
	/// �����ƶ�ʱ�����µĿ�Ƭ
	/// </summary>
	void GameClientDeckWindow::ScrollingChangeLoadCard() {
		
	}
}