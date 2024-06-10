/*
�����ˣ���������
�������ڣ�2024-6-8
������
*/
#pragma once
#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QList>
#include "../Client/clientcard.h"
#include "cscrollarea .h"
namespace GameClient::Component {
	using namespace GameClient::Client;
	class CardSearchScrollArea {
		public:
			CardSearchScrollArea() {};
			CardSearchScrollArea(QFont* pfont,QWidget* parent);
			void LoadCards(QList<ClientCard*> cards);
			CScrollArea *scrollArea;//��������������
		private:
			QWidget *container;//��ֱ����������
			QVBoxLayout *layout;//��ֱ������
			QFont* pfont;
			QWidget* parent;
	};

#define SCROLLAREA_STYLE  R"(
				QScrollBar:vertical {
					border: none;
                    border-style: solid;
                    border-width: 0px 1px 0px 0px;
					background: transparent;
					width: 15px;
				}
				QScrollBar::handle:vertical {
					background: #74777B;
					min-height: 20px;
					border-radius: 5px;
				}
				QScrollBar::add-line:vertical {
					background: none;
				}
				QScrollBar::sub-line:vertical {
					background: none;
				}
				QScrollBar::sub-page:vertical {
					background: none;
				}
				QScrollBar::add-page:vertical {
					background: none;
				}
			)"
}