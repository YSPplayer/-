/*
�����ˣ���������
�������ڣ�2024-6-8
������
*/
#include "cardsearchscrollarea.h"
#include "cardsearchcontainer.h"
#include <QScrollBar>
#include "Util/qutil.h"
namespace GameClient::Component { 
    using namespace GameClient::Tool;
	CardSearchScrollArea::CardSearchScrollArea(QFont* pfont,QWidget* parent):pfont(pfont),parent(parent) {
		scrollArea = new CScrollArea(parent);
        scrollArea->setWidgetResizable(true); //������������ڲ����ݵ�����С
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // ��ֱ������������Ҫ��ʾ
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// ˮƽ������������ʾ
        scrollArea->resize(parent->width(), parent->height());
        QScrollBar *vScrollBar = scrollArea->verticalScrollBar();
        scrollArea->setStyleSheet(SCROLLAREA_STYLE);
        container= new QWidget();
        container->setStyleSheet("border: none;");
        layout = new QVBoxLayout(container);
        layout->setSpacing(5);//��ֱ�������Ϊ10
        layout->setContentsMargins(5, 5, 0, 5); //����layout�ļ�࣬�Ҳ಻������
        //���ò��ֺ͹��������viewport
        scrollArea->setWidget(container);
	}

    /// <summary>
    /// �������п�Ƭ������������
    /// </summary>
    /// <param name="cards"></param>
    void CardSearchScrollArea::LoadCards(QList<ClientCard*> cards) {
        qint32 width = parent->width();
        qint32 height = static_cast<qint32>((parent->height() - 35) / 6);//��Ҫ��ȥ7������ĸ߶�
        //Ĭ�ϵļ��
        qint32 x = 5; //10
        qint32 y = 0;//5
        qint32 imageHeight = height - y * 2;
        qint32 imageWidth =  static_cast<qint32>(static_cast<double>(imageHeight) / 1.4);//������ϵ
        qint32 tx = x * 4 + imageWidth;
        qint32 labelWidth = width - tx;
        qint32 labelHeight = static_cast<qint32>(static_cast<double>(imageHeight) / 3);
        qint32 tyTextName = y;
        qint32 tytextAttribute = tyTextName + labelHeight;
        qint32 textAd = tytextAttribute + labelHeight;
        scrollArea->verticalScrollBar()->setSingleStep(height + 5); 
        for(qint32 i = 0; i < 6; ++i) { //ֻ��ȡǰ5����������ʾ
            ClientCard* card = cards[i];
            CardSearchContainer* cardContainer = new CardSearchContainer(QPixmap(QUtil::GetImagePath(card->id)),pfont,parent);
            cardContainer->resize(width,height);
            cardContainer->setMinimumSize(width,height);
            cardContainer->imageCard->setGeometry(x,y,imageWidth,imageHeight);
            cardContainer->textName->setGeometry(tx,tyTextName,labelWidth,labelHeight);
            cardContainer->textAttribute->setGeometry(tx,tytextAttribute,labelWidth,labelHeight);
            cardContainer->textAd->setGeometry(tx,textAd,labelWidth,labelHeight);
            cardContainer->SetText(card->name,card->attribute,card->race,card->level,card->atk,card->def);
            layout->addWidget(cardContainer);

        }
        cards.resize(12);
        //վλ��������ȷ���������ĳ���
        QWidget* StationContainer = new QWidget(parent);
        qint32 containerHeight = height * (cards.size() - 6) + 5 * (cards.size() - 7);
        StationContainer->resize(width,height * containerHeight);
        StationContainer->setMinimumSize(width,height * containerHeight);
        StationContainer->setStyleSheet("border: none;");
        layout->addWidget(StationContainer);

    }
}