/*
�����ˣ���������
�������ڣ�2024-6-8
������
*/
#pragma once
#include "../Component/imagecard.h"
#include "../Enum/enumtype.h"
namespace GameClient::Client {
	using namespace GameClient::Component;
	using namespace GameClient::GameEnum;
	struct Value {
		qint32 value;
		ValueType vtype;
	};
	class ClientCard : public ImageCard {
		Q_OBJECT
	public:
		ClientCard(quint64 id, quint32 ot, quint64 alias, quint64 type, quint32 level,
			quint64 attribute, quint64 race, const Value& atk, const Value& def, const QString& desc,
			const QPixmap& image,qint32 width,qint32 height,QWidget* parent = nullptr); 
		~ClientCard();
	private:
		quint64 id;//����
		quint32 ot;//��Ƭ�������
		quint64 alias;//��Ƭ����
		quint64 type;//��Ƭ���
		quint32 level;//�ȼ�
		quint64 attribute;//����
		quint64 race;//����
		Value atk;//������
		Value def;//�ر���
		QString desc;//�ı�����
	};
}