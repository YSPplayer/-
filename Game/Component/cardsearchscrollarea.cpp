/*
创建人：神数不神
创建日期：2024-6-8
无修正
*/
#include "cardsearchscrollarea.h"
#include "cardsearchcontainer.h"
#include <QScrollBar>
namespace GameClient::Component { 
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

        // 添加多个子QWidget
        for (int i = 0; i < 100; i++) {
            CardSearchContainer* cr = new CardSearchContainer(pfont,parent);
            layout->addWidget(cr);
        }
	}
}