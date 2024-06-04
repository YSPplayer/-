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
		DeckEditContainer(){};
		DeckEditContainer(QWidget* parent,qint32 yCardNumber = 1);
		void AddImageCard(ImageCard* imageCard);
		inline qint32 GetImageWidth() {
			return imageWidth;
		};
		inline qint32 GetImageHeight() {
			return imageHeight;  
		};
	private:
		QWidget* parent;
		QList<ImageCard*> imageCards;
		qint32 lineLength;//标准容纳卡片所需要的总长度
		qint32 maxNumber;//当前容器状态位置下的卡片最大值
		qint32 width;
		qint32 height;
		qint32 imageWidth;
		qint32 imageHeight;
		qint32 xSpacing;
		qint32 ySpacing;
		qint32 xCardNumber;//每行最多的卡片存储量
		qint32 yCardNumber;//每列最多的卡片存储量
		qint32 xOffset;//卡片之间需要叠放的距离
		QRect GetImageCardGeometry(ImageCard* imageCard);
		void SetLineNumber(qint32 size);
	};
}