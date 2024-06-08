/*
�����ˣ���������
�������ڣ�2024-6-5
������
*/
#pragma once
#include <Qwidget>
#include <QLabel>
#include "imagecard.h"
namespace GameClient::Component {
	class CardSearchContainer : public QWidget {
			Q_OBJECT
		public:
			CardSearchContainer(QFont* pfont,QWidget* parent = nullptr);
		private:
			ImageCard* card;
			QLabel* textName;
			QLabel* textAttribute;
			QLabel* textAd;
			bool hovered;
		protected:
			void enterEvent(QEnterEvent *event) override;
			void leaveEvent(QEvent *event) override;
			void paintEvent(QPaintEvent *event) override;
			void mousePressEvent(QMouseEvent *event) override;
		signals:
			void rightClicked();
	};
}