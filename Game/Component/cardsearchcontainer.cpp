/*
�����ˣ���������
�������ڣ�2024-6-5
������
*/
#include "cardsearchcontainer.h"
#include <QPainter>
#include <QMouseEvent>
#include "Util/qutil.h"
namespace GameClient::Component { 
	using namespace GameClient::Tool;
	CardSearchContainer::CardSearchContainer(QFont* pfont,QWidget* parent):QWidget(parent) {
		hovered = false;
		setCursor(Qt::PointingHandCursor);
		setAttribute(Qt::WA_Hover, true);
		setStyleSheet("border: none;");
		//����Ĭ�ϵĴ�С��ÿ�������ʾ7�ſ�
		resize(parent->width(),static_cast<qint32>(parent->height() / 6));
		//������С�ߴ磬������봹ֱ���ֹ������лᱻĬ��ѹ��
		setMinimumSize(parent->width(),static_cast<qint32>(parent->height() / 6)); 
		//Ĭ�ϵļ��
		qint32 x = 5; //10
		qint32 y = 0;//5
		qint32 imageHeight = height() - y * 2;
		qint32 imageWidth =  static_cast<qint32>(static_cast<double>(imageHeight) / 1.4);//������ϵ
		card = new ImageCard(QPixmap(QUtilGetRootPath() + "/Resources/Pics/2511.jpg"),imageWidth,imageHeight,this);
		card->move(x,y);
		qint32 labelHeight = static_cast<qint32>(static_cast<double>(imageHeight) / 3);
		qint32 tx = x * 4 + imageWidth;
		qint32 ty = y;
		qint32 labelWidth = width() - tx;
		textName = new QLabel(this);
		textName->setGeometry(tx,ty,labelWidth,labelHeight);
		textName->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
		textName->setText("\345\271\273\347\245\236\345\205\275\55\347\277\274\347\245\236\351\276\231\344\271\213\346\200\250");
		textName->setStyleSheet("QLabel { color: rgb(199, 195, 195); border: none; }");
		QUtil::SetWidgetFont(pfont,textName,14);
		ty += labelHeight;
		textAttribute = new QLabel(this);
		textAttribute->setGeometry(tx,ty,labelWidth,labelHeight);
		textAttribute->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
		textAttribute->setText("\347\245\236\57\345\271\273\347\245\236\345\205\275\40\342\230\205\66");
		textAttribute->setStyleSheet("QLabel { color: rgb(199, 195, 195); border: none; }");
		QUtil::SetWidgetFont(pfont,textAttribute,14);
		ty += labelHeight;
		textAd = new QLabel(this);
		textAd->setGeometry(tx,ty,labelWidth,labelHeight);
		textAd->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
		textAd->setText("\62\67\60\60\57\62\63\60\60\133\132\103\107\135");
		textAd->setStyleSheet("QLabel { color: rgb(199, 195, 195); border: none; }");
		QUtil::SetWidgetFont(pfont,textAd,14);
	}

	void CardSearchContainer::enterEvent(QEnterEvent* event) {
		hovered = true;
		update();
		QWidget::enterEvent(event);
	}

	void CardSearchContainer::leaveEvent(QEvent* event) {
		hovered = false;
		update();
		QWidget::leaveEvent(event);
	}

	void CardSearchContainer::paintEvent(QPaintEvent* event) {
		QPainter painter(this);
		if (hovered) {
			painter.fillRect(rect(), QColor(66, 66, 73, 100)); // �����ͣʱ�ı���ɫ
		} else {
			painter.fillRect(rect(), QColor(0,0,0,0)); // Ĭ�ϱ���ɫ
		}
		QWidget::paintEvent(event);
	}

	void CardSearchContainer::mousePressEvent(QMouseEvent* event) {
		if (event->button() == Qt::RightButton) emit rightClicked();
		QWidget::mousePressEvent(event);
	}
}