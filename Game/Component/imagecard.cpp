/*
创建人：神数不神
创建日期：2024-6-3
无修正
*/
#include "imagecard.h"
namespace GameClient::Component {
	ImageCard::ImageCard(const QPixmap& image,qint32 x,qint32 y,qint32 width,qint32 heigth,QWidget* parent):QLabel(parent) {
		setGeometry(x,y,width,heigth);
		setPixmap(image.scaled(size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
	}
	 

	ImageCard::~ImageCard(){}

	void ImageCard::mousePressEvent(QMouseEvent* event) {
		emit clicked();
		QLabel::mousePressEvent(event); 
	}
}