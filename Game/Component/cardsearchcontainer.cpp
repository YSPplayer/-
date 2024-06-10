/*
创建人：神数不神
创建日期：2024-6-5
无修正
*/
#include "cardsearchcontainer.h"
#include <QPainter>
#include <QMouseEvent>
#include "Util/qutil.h"
namespace GameClient::Component { 
	using namespace GameClient::Tool;
	CardSearchContainer::CardSearchContainer(const QPixmap& image,QFont* pfont,QWidget* parent):QWidget(parent) {
		hovered = false;
		setCursor(Qt::PointingHandCursor);
		setAttribute(Qt::WA_Hover, true);
		setStyleSheet("border: none;");
		imageCard = new ImageCard(image,this);
		textName = new QLabel(this);
		textName->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
		textName->setStyleSheet("QLabel { color: rgb(199, 195, 195); border: none; }");
		QUtil::SetWidgetFont(pfont,textName,14);
		textAttribute = new QLabel(this);
		textAttribute->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
		textAttribute->setStyleSheet("QLabel { color: rgb(199, 195, 195); border: none; }");
		QUtil::SetWidgetFont(pfont,textAttribute,14);
		textAd = new QLabel(this);
		textAd->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
		textAd->setText("\62\67\60\60\57\62\63\60\60\133\132\103\107\135");
		textAd->setStyleSheet("QLabel { color: rgb(199, 195, 195); border: none; }");
		QUtil::SetWidgetFont(pfont,textAd,14);
	}

	/// <summary>
	/// 设置文本
	/// </summary>
	/// <param name="name"></param>
	/// <param name="attribute"></param>
	/// <param name="race"></param>
	/// <param name="level"></param>
	/// <param name="atk"></param>
	/// <param name="def"></param>
	void CardSearchContainer::SetText(const QString& name, quint64 attribute, quint64 race, qint64 level, Value atk, Value def) {
		textName->setText(name);
		textAttribute->setText(QUtil::GetAttributeText(attribute) + "/" + 
			QUtil::GetRaceText(race) + " \342\230\205" + QString::number(level));
		textAd->setText(QUtil::GetValueText(atk) + "/" + QUtil::GetValueText(def));
	}

	/// <summary>
	/// 设置图片
	/// </summary>
	/// <param name="image"></param>
	void CardSearchContainer::SetImage(const QPixmap& image) {
		imageCard->SetImage(image);
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
			painter.fillRect(rect(), QColor(66, 66, 73, 100)); // 鼠标悬停时的背景色
		} else {
			painter.fillRect(rect(), QColor(0,0,0,0)); // 默认背景色
		}
		QWidget::paintEvent(event);
	}

	void CardSearchContainer::mousePressEvent(QMouseEvent* event) {
		if (event->button() == Qt::RightButton) emit rightClicked();
		QWidget::mousePressEvent(event);
	}
}