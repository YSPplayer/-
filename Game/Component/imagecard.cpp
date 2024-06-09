/*
创建人：神数不神
创建日期：2024-6-3
无修正
*/
#include "imagecard.h"
namespace GameClient::Component {
	ImageCard::ImageCard(const QPixmap& image,qint32 width,qint32 height,QWidget* parent):QLabel(parent),image(image) {
		resize(width,height);
	}

	ImageCard::ImageCard(const QPixmap& image,QWidget* parent):QLabel(parent),image(image)  {}

	ImageCard::~ImageCard(){}

	void ImageCard::mousePressEvent(QMouseEvent* event) {
		emit clicked();
		QLabel::mousePressEvent(event); 
	}

	void ImageCard::resizeEvent(QResizeEvent* event) {
		setPixmap(image.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		QLabel::resizeEvent(event); 
	}
}