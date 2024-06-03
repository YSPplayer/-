/*
�����ˣ���������
�������ڣ�2024-6-3
������
*/
#include "deckeditcontainer.h"
namespace GameClient::Component {

	DeckEditContainer::DeckEditContainer(QWidget* parent) {
		this->parent = parent;
		width = this->parent->width();
		height =this->parent->height();
		xSpacing = DECKEDITCONTAINER_X_SPACING;
		ySpacing = DECKEDITCONTAINER_Y_SPACING;
		lineCardNumber = DECKEDITCONTAINER_LINE_CARD_NUMBER;
		imageWidth = static_cast<qint32>((width - (lineCardNumber + 1) * xSpacing) / lineCardNumber);
		imageHeight = static_cast<qint32>((height - (4 + 1) * ySpacing) / 4);
		currentX = 0;
		currentY = 0;
		for(qint32 i = 0;i < 4; ++i) {
			QList<ImageCard*> lineImageCards;
			for(qint32 j = 0; j < lineCardNumber; ++j) {
				lineImageCards.append(nullptr);
			}
			imageCards.append(lineImageCards);
		}
	}

	/// <summary>
	/// �����м��뿨Ƭ
	/// </summary>
	/// <param name="imageCard"></param>
	void DeckEditContainer::AddImageCard(ImageCard* imageCard) {
		imageCards[currentY][currentX] = imageCard;
		imageCard->setGeometry(GetImageCardGeometry(currentX,currentY));
		++currentX;
		if(currentX >= lineCardNumber) {
			currentX = 0;
			++currentY;
		}
	}

	/// <summary>
	/// ��ȡ����ǰ��Ƭ�ķ���λ��
	/// </summary>
	/// <param name="currentX"></param>
	/// <param name="currentY"></param>
	/// <returns></returns>
	QRect DeckEditContainer::GetImageCardGeometry(qint32 currentX, qint32 currentY) {
		qint32 x = (currentX + 1) * xSpacing + currentX * imageWidth;
		qint32 y = (currentY + 1) * ySpacing + currentY * imageHeight;
		return QRect(x,y,imageWidth,imageHeight);
	}
	
	/// <summary>
	/// ��ȡ��ǰ��������������һ������
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	bool DeckEditContainer::GetImageCardsLastIndex(qint32 currentX,qint32 currentY,qint32& x, qint32& y) {
		x = currentX - 1;
		if(x < 0) {
			x = lineCardNumber - 1;
			y = currentY - 1;
			if(y < 0) return false;
		} else {
			y = currentY;
		}
		return true;
	}

	/// <summary>
	/// ��ȡ��ǰ��������һ������
	/// </summary>
	/// <param name="currentX"></param>
	/// <param name="currentY"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	bool DeckEditContainer::GetImageCardsNextIndex(qint32 currentX, qint32 currentY, qint32& x, qint32& y) {
		return false;
	}
}