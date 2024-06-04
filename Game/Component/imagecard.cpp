/*
�����ˣ���������
�������ڣ�2024-6-3
������
*/
#include "imagecard.h"
namespace GameClient::Component {
	ImageCard::ImageCard(const QPixmap& image,qint32 width,qint32 height,QWidget* parent):QLabel(parent) {
		resize(width,height);
		setPixmap(image.scaled(size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	}

	ImageCard::~ImageCard(){}

	void ImageCard::mousePressEvent(QMouseEvent* event) {
		emit clicked();
		QLabel::mousePressEvent(event); 
	}
}