/*
�����ˣ���������
�������ڣ�2024-6-3
������
*/
#pragma once
#include <QLabel>
namespace GameClient::Component {
	class ImageCard : public QLabel {
		Q_OBJECT
		public:
			ImageCard(const QPixmap& image,QWidget* parent = nullptr);
			ImageCard(const QPixmap& image,qint32 width,qint32 height,QWidget* parent = nullptr);
			~ImageCard();
		protected:
			void mousePressEvent(QMouseEvent* event) override;
			void resizeEvent(QResizeEvent* event) override;
		private:
			QPixmap image;
		signals:
			void clicked();
	};
}