/*
�����ˣ���������
�������ڣ�2024-6-5
������
*/
#pragma once
#include <Qwidget>
#include <QLabel>
#include "imagecard.h"
#include "cardsearchscrollarea.h"
namespace GameClient::Component {
	using namespace GameClient::Client;
	class CardSearchContainer : public QWidget {
			Q_OBJECT
		public:
			friend CardSearchScrollArea;
			CardSearchContainer(const QPixmap& image,QFont* pfont,QWidget* parent = nullptr);
		private:
			bool hovered;
			ImageCard* imageCard;
			QLabel* textName;
			QLabel* textAttribute;
			QLabel* textAd;
		protected:
			void enterEvent(QEnterEvent *event) override;
			void leaveEvent(QEvent *event) override;
			void paintEvent(QPaintEvent *event) override;
			void mousePressEvent(QMouseEvent *event) override;
		signals:
			void rightClicked();
	};
}