/*
创建人：神数不神
创建日期：2024-6-5
无修正
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
			void SetText(const QString& name,quint64 attribute,quint64 race,qint64 level,Value atk,Value def);
			void SetImage(const QPixmap& image);
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