/*
创建人：神数不神
创建日期：2024-6-8
无修正
*/
#include "cardsearchscrollarea.h"
#include "cardsearchcontainer.h"
#include <QScrollBar>
#include "Util/qutil.h"
namespace GameClient::Component { 
    using namespace GameClient::Tool;
	CardSearchScrollArea::CardSearchScrollArea(QFont* pfont,QWidget* parent):pfont(pfont),parent(parent) {
		scrollArea = new QScrollArea(parent);
        scrollArea->setWidgetResizable(true); //允许滚动区域内部内容调整大小
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // 垂直滚动条根据需要显示
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// 水平滚动条永不显示
        scrollArea->resize(parent->width(), parent->height());
        QScrollBar *vScrollBar = scrollArea->verticalScrollBar();
        vScrollBar->setSingleStep(static_cast<qint32>(parent->height() / 6) + 5);//设置滚动步长
        scrollArea->setStyleSheet(SCROLLAREA_STYLE);
        container= new QWidget();
        container->setStyleSheet("border: none;");
        layout = new QVBoxLayout(container);
        layout->setSpacing(10);//垂直间隔设置为10
        //设置布局和滚动区域的viewport
        scrollArea->setWidget(container);
	}

    /// <summary>
    /// 加载所有卡片到卡组容器中
    /// </summary>
    /// <param name="cards"></param>
    void CardSearchScrollArea::LoadCards(QList<ClientCard*> cards) {
        qint32 width = parent->width();
        qint32 height = static_cast<qint32>(parent->height() / 6);
        //默认的间距
        qint32 x = 5; //10
        qint32 y = 0;//5
        qint32 imageHeight = height - y * 2;
        qint32 imageWidth =  static_cast<qint32>(static_cast<double>(imageHeight) / 1.4);//倍数关系
        qint32 tx = x * 4 + imageWidth;
        qint32 labelWidth = width - tx;
        qint32 labelHeight = static_cast<qint32>(static_cast<double>(imageHeight) / 3);
        qint32 tyTextName = y;
        qint32 tytextAttribute = tyTextName + labelHeight;
        qint32 textAd = tytextAttribute + labelHeight;
        qint32 times = 0;
        for(auto card : cards) {
            ++times;
            if(times >= 100) break;
            CardSearchContainer* cardContainer = new CardSearchContainer(QPixmap(QUtil::GetImagePath(card->id)),pfont,parent);
            cardContainer->resize(width,height);
            cardContainer->setMinimumSize(width,height);
            cardContainer->imageCard->setGeometry(x,y,imageWidth,imageHeight);
            cardContainer->textName->setGeometry(tx,tyTextName,labelWidth,labelHeight);
            cardContainer->textName->setText(card->name);
            cardContainer->textAttribute->setGeometry(tx,tytextAttribute,labelWidth,labelHeight);
            cardContainer->textAttribute->setText(QUtil::GetAttributeText(card->attribute) + "/" + 
                QUtil::GetRaceText(card->race) + " \342\230\205" + QString::number(card->level));
            cardContainer->textAd->setGeometry(tx,textAd,labelWidth,labelHeight);
            cardContainer->textAd->setText(QUtil::GetValueText(card->atk) + "/" + QUtil::GetValueText(card->def));
            layout->addWidget(cardContainer);
        }
    }
}