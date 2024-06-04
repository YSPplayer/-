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
		height = this->parent->height();
		xSpacing = DEFAULT_DECKEDITCONTAINER_X_SPACING;
		ySpacing = DEFAULT_DECKEDITCONTAINER_Y_SPACING;
		xCardNumber = DEFAULT_DECKEDITCONTAINER_X_CARD_NUMBER;
		yCardNumber = DEFAULT_DECKEDITCONTAINER_Y_CARD_NUMBER;
		maxNumber = xCardNumber * yCardNumber;
		lineLength = width - 2;//Ĭ����С1�����
		imageWidth = static_cast<qint32>((width - (xCardNumber + 1) * xSpacing) / xCardNumber);
		imageHeight = static_cast<qint32>((height - (yCardNumber + 1) * ySpacing) / yCardNumber);
		xOffset = 0;
		imageCards.resize(0);
	/*	for(qint32 i = 0;i < yCardNumber; ++i) {
			QList<ImageCard*> lineImageCards;
			for(qint32 j = 0; j < xCardNumber; ++j) {
				lineImageCards.append(nullptr);
			}
			imageCards.append(lineImageCards);
		}*/
	}

	/// <summary>
	/// �����м��뿨Ƭ
	/// </summary>
	/// <param name="imageCard"></param>
	void DeckEditContainer::AddImageCard(ImageCard* imageCard) {
		//��ȡ��һ������Ŀ�Ƭ��Ϣ
		ImageCard* lastImageCard = imageCards.size() >= 1 ? imageCards[imageCards.size() - 1] : nullptr;
		SetLineNumber(imageCards.size() + 1);//��������������ΪҪ��ӿ�Ƭ�������������� + 1
		imageCard->setGeometry(GetImageCardGeometry(lastImageCard));
		if(lastImageCard) lastImageCard->stackUnder(imageCard);
		imageCards.append(imageCard);//��ǰ�����ʱ�޸ĵ��ڴ�ֵ��Ч
		
	}

	/// <summary>
	/// ��ȡ����ǰ��Ƭ�ķ���λ��
	/// </summary>
	/// <param name="imageCard"></param>
	/// <returns></returns>
	QRect DeckEditContainer::GetImageCardGeometry(ImageCard* imageCard) {
		if(imageCard) {
			const QRect& rect = imageCard->geometry();
			qint32 size = imageCards.size();
			if(size < 40) {
				if(size % xCardNumber == 0) {//˵����ǰ�Ŀ�Ƭλ�����Ҳ࣬������Ҫ������ʾͼƬ
					return QRect(DEFAULT_DECKEDITCONTAINER_X_SPACING,rect.y() + rect.height() + ySpacing, rect.width(), rect.height());
				} else {//�ڸÿ�Ƭ�ĺ���λ������ʾ���ǵ�ͼƬ
					return QRect(rect.x() + rect.width() + xSpacing,rect.y(), rect.width(), rect.height());
				}
			} else {
				qint32 flineLength = imageWidth * xCardNumber;//��ȡ���г��ȣ�����40��ʱ���Ϊ0
				qint32 cimageWidth = imageWidth;//�и���ͼƬ���ȣ��������ͼƬ���ŵļ��
				//�µ���ʼ���
				qint32 cxSpacing = xSpacing;
				while(flineLength > lineLength) {
					//��಻�����ֲ����ȣ��õ��ŷ�ʽ�ֲ���ע�⣬���һ�ſ�Ƭ�������Ŀ��
					--cimageWidth;
					flineLength = cimageWidth * (xCardNumber - 1) + imageWidth;
				}
				cxSpacing = static_cast<qint32>(std::round(((static_cast<double>(lineLength - flineLength)) / 2))) + 1;
				//�ٴθ���
				xOffset = imageWidth - cimageWidth;
				for(qint32 i = 0; i < imageCards.count(); ++i) {
					ImageCard* cimageCard = imageCards[i];
					if(i > 0) {
						ImageCard* lastImageCard = imageCards[i - 1];
						const QRect& rect = lastImageCard->geometry();
						if(i % xCardNumber == 0) { //��Ƭλ�������Ҳ࣬��Ҫ������ʾ
							cimageCard->move(cxSpacing,rect.y() + rect.height() + ySpacing);
						} else {
							cimageCard->move(rect.x() + rect.width() - xOffset,rect.y());
						}
					} else {
						cimageCard->move(cxSpacing,cimageCard->y());
					}
				}
				//����rect��ֵ
				const QRect& newRect = imageCard->geometry();
				//�������ǵ�ǰ�Ŀ�Ƭλ��
				return QRect(newRect.x() + rect.width()  - xOffset,rect.y(), rect.width(), rect.height());
			}

		} else {
			//��һ�ſ���λ��ʼ�չ̶���ע�����������Ҳ�ļ��ʼ���ǹ̶��ģ������ó���
			return QRect(DEFAULT_DECKEDITCONTAINER_X_SPACING,DEFAULT_DECKEDITCONTAINER_Y_SPACING,imageWidth,imageHeight);
		}	
	}

	/// <summary>
	/// ��ȡ����ǰ����Ӧ���е����Ƭ����
	/// </summary>
	/// <returns></returns>
	void DeckEditContainer::SetLineNumber(qint32 size) {
		if(size > maxNumber) {
			++xCardNumber;
			maxNumber = xCardNumber * yCardNumber;
		}
	}

}