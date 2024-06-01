/*
创建人：神数不神
创建日期：2024-6-1
无修正
*/
#pragma once
#include <QStyledItemDelegate>
#include <QPainter>
#include <QPainterPath>
namespace GameClient::Component {
	class ComboBoxDelegate : public QStyledItemDelegate {
        public:
            using QStyledItemDelegate::QStyledItemDelegate;
            ComboBoxDelegate() {
                font = nullptr;
                size = 13;
                selectColor = QPalette::Base;
                itemHeight = 20;
            };

            inline void SetFont(QFont* font, qint32 size) {
                this->font = font;
                this->size = size;
            }

            inline void SetSelectColor(const QColor& selectColor) {
                this->selectColor = selectColor;
            }

            inline void SetItemHeight(qint32 itemHeight) {
                this->itemHeight = itemHeight;
            }

            QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override {
                QSize defaultSize = QStyledItemDelegate::sizeHint(option, index);
                return QSize(defaultSize.width(), itemHeight);
            }

            void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
                QStyleOptionViewItem opt(option);
                initStyleOption(&opt, index);
                painter->save();
                if (option.state & QStyle::State_Selected) {
                    painter->fillRect(opt.rect, selectColor);
                    painter->setPen(opt.palette.color(QPalette::Text)); 
                }
                else {
                    painter->fillRect(opt.rect, opt.palette.color(QPalette::Base));
                    painter->setPen(opt.palette.color(QPalette::Text)); 
                }
                if (font) {
                    font->setPointSize(size);
                    painter->setFont(*font);
                } 
                const QRect& rect = opt.rect;
                const QString& text = opt.text;
                QTextOption textOption(Qt::AlignCenter); 
                painter->drawText(rect, text, textOption);
                painter->restore();
            }
        private:
            QFont* font;
            qint32 size;
            qint32 itemHeight;
            QColor selectColor;
	};
}