/*
创建人：神数不神
创建日期：2024-6-3
无修正
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
		lineLength = width - 2;//默认最小1个间距
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
	/// 容器中加入卡片
	/// </summary>
	/// <param name="imageCard"></param>
	void DeckEditContainer::AddImageCard(ImageCard* imageCard) {
		//获取上一张排序的卡片信息
		ImageCard* lastImageCard = imageCards.size() >= 1 ? imageCards[imageCards.size() - 1] : nullptr;
		SetLineNumber(imageCards.size() + 1);//更新行数量，因为要添加卡片，所以这里我们 + 1
		imageCard->setGeometry(GetImageCardGeometry(lastImageCard));
		if(lastImageCard) lastImageCard->stackUnder(imageCard);
		imageCards.append(imageCard);//在前面添加时修改的内存值无效
		
	}

	/// <summary>
	/// 获取到当前卡片的放置位置
	/// </summary>
	/// <param name="imageCard"></param>
	/// <returns></returns>
	QRect DeckEditContainer::GetImageCardGeometry(ImageCard* imageCard) {
		if(imageCard) {
			const QRect& rect = imageCard->geometry();
			qint32 size = imageCards.size();
			if(size < 40) {
				if(size % xCardNumber == 0) {//说明当前的卡片位于最右侧，我们需要换行显示图片
					return QRect(DEFAULT_DECKEDITCONTAINER_X_SPACING,rect.y() + rect.height() + ySpacing, rect.width(), rect.height());
				} else {//在该卡片的后面位置来显示我们的图片
					return QRect(rect.x() + rect.width() + xSpacing,rect.y(), rect.width(), rect.height());
				}
			} else {
				qint32 flineLength = imageWidth * xCardNumber;//获取单行长度，大于40张时间距为0
				qint32 cimageWidth = imageWidth;//切割后的图片长度，差额用于图片叠放的间距
				//新的起始间距
				qint32 cxSpacing = xSpacing;
				while(flineLength > lineLength) {
					//间距不足以弥补长度，用叠放方式弥补，注意，最后一张卡片是完整的宽度
					--cimageWidth;
					flineLength = cimageWidth * (xCardNumber - 1) + imageWidth;
				}
				cxSpacing = static_cast<qint32>(std::round(((static_cast<double>(lineLength - flineLength)) / 2))) + 1;
				//再次更新
				xOffset = imageWidth - cimageWidth;
				for(qint32 i = 0; i < imageCards.count(); ++i) {
					ImageCard* cimageCard = imageCards[i];
					if(i > 0) {
						ImageCard* lastImageCard = imageCards[i - 1];
						const QRect& rect = lastImageCard->geometry();
						if(i % xCardNumber == 0) { //卡片位置在最右侧，需要换行显示
							cimageCard->move(cxSpacing,rect.y() + rect.height() + ySpacing);
						} else {
							cimageCard->move(rect.x() + rect.width() - xOffset,rect.y());
						}
					} else {
						cimageCard->move(cxSpacing,cimageCard->y());
					}
				}
				//更新rect的值
				const QRect& newRect = imageCard->geometry();
				//返回我们当前的卡片位置
				return QRect(newRect.x() + rect.width()  - xOffset,rect.y(), rect.width(), rect.height());
			}

		} else {
			//第一张卡的位置始终固定，注意最左侧和左右侧的间距始终是固定的，所以用常量
			return QRect(DEFAULT_DECKEDITCONTAINER_X_SPACING,DEFAULT_DECKEDITCONTAINER_Y_SPACING,imageWidth,imageHeight);
		}	
	}

	/// <summary>
	/// 获取到当前行数应该有的最大卡片数量
	/// </summary>
	/// <returns></returns>
	void DeckEditContainer::SetLineNumber(qint32 size) {
		if(size > maxNumber) {
			++xCardNumber;
			maxNumber = xCardNumber * yCardNumber;
		}
	}

}