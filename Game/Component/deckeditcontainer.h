/*
�����ˣ���������
�������ڣ�2024-6-3
������
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
		qint32 lineLength;//��׼���ɿ�Ƭ����Ҫ���ܳ���
		qint32 maxNumber;//��ǰ����״̬λ���µĿ�Ƭ���ֵ
		qint32 width;
		qint32 height;
		qint32 imageWidth;
		qint32 imageHeight;
		qint32 xSpacing;
		qint32 ySpacing;
		qint32 xCardNumber;//ÿ�����Ŀ�Ƭ�洢��
		qint32 yCardNumber;//ÿ�����Ŀ�Ƭ�洢��
		qint32 xOffset;//��Ƭ֮����Ҫ���ŵľ���
		QRect GetImageCardGeometry(ImageCard* imageCard);
		void SetLineNumber(qint32 size);
	};
}