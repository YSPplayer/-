/*
创建人：神数不神
创建日期：2024-6-3
无修正
*/
#pragma once
#include "imagecard.h"
#include "../Tag/dfwindow.h"
#include <QList>
namespace GameClient::Component { 
	class DeckEditContainer {
	public:
		DeckEditContainer(QWidget* parent);
		void AddImageCard(ImageCard* imageCard);
	private:
		QWidget* parent;
		QList<QList<ImageCard*>> imageCards;
		qint32 width;
		qint32 height;
		qint32 imageWidth;
		qint32 imageHeight;
		qint32 xSpacing;
		qint32 ySpacing;
		qint32 lineCardNumber;//每行最多的卡片存储量
		qint32 currentX;//当前的容器最后一个卡片定位的索引位置
		qint32 currentY;//当前的容器最后一个卡片定位的索引位置
		QRect GetImageCardGeometry(qint32 currentX,qint32 currentY);
		bool GetImageCardsLastIndex(qint32 currentX,qint32 currentY,qint32& x, qint32& y);
		bool GetImageCardsNextIndex(qint32 currentX,qint32 currentY,qint32& x, qint32& y);
	};
}