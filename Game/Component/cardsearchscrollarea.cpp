/*
�����ˣ���������
�������ڣ�2024-6-8
������
*/
#include "cardsearchscrollarea.h"
#include "cardsearchcontainer.h"
#include <QScrollBar>
namespace GameClient::Component { 
	CardSearchScrollArea::CardSearchScrollArea(QFont* pfont,QWidget* parent):pfont(pfont),parent(parent) {
		scrollArea = new QScrollArea(parent);
        scrollArea->setWidgetResizable(true); //������������ڲ����ݵ�����С
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // ��ֱ������������Ҫ��ʾ
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);// ˮƽ������������ʾ
        scrollArea->resize(parent->width(), parent->height());
        QScrollBar *vScrollBar = scrollArea->verticalScrollBar();
        vScrollBar->setSingleStep(static_cast<qint32>(parent->height() / 6) + 5);//���ù�������
        scrollArea->setStyleSheet(SCROLLAREA_STYLE);
        container= new QWidget();
        container->setStyleSheet("border: none;");
        layout = new QVBoxLayout(container);
        layout->setSpacing(10);//��ֱ�������Ϊ10
        //���ò��ֺ͹��������viewport
        scrollArea->setWidget(container);

        // ��Ӷ����QWidget
        for (int i = 0; i < 100; i++) {
            CardSearchContainer* cr = new CardSearchContainer(pfont,parent);
            layout->addWidget(cr);
        }
	}
}