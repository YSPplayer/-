/*
创建人：神数不神
创建日期：2024-6-3
无修正
*/
#pragma once
#include <QLabel>
namespace GameClient::Component {
	class ImageCard : public QLabel {
		Q_OBJECT
		public:
			ImageCard(const QPixmap& image,qint32 x,qint32 y,qint32 width,qint32 heigth,QWidget* parent = nullptr);
			~ImageCard();
		protected:
			void mousePressEvent(QMouseEvent* event) override;
		signals:
			void clicked();
	};
}