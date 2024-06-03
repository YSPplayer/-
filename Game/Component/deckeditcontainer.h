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
		qint32 lineCardNumber;//ÿ�����Ŀ�Ƭ�洢��
		qint32 currentX;//��ǰ���������һ����Ƭ��λ������λ��
		qint32 currentY;//��ǰ���������һ����Ƭ��λ������λ��
		QRect GetImageCardGeometry(qint32 currentX,qint32 currentY);
		bool GetImageCardsLastIndex(qint32 currentX,qint32 currentY,qint32& x, qint32& y);
		bool GetImageCardsNextIndex(qint32 currentX,qint32 currentY,qint32& x, qint32& y);
	};
}