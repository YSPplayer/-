/*
�����ˣ���������
�������ڣ�2024-6-8
������
*/
#pragma once
#include <QObject>
#include "../Enum/enumtype.h"
namespace GameClient::Client {
	using namespace GameClient::GameEnum;
	struct Value {
		qint32 value;
		ValueType vtype;
	};
	class ClientCard {
	public:
		ClientCard(quint64 id, quint32 ot, quint64 alias, quint64 type, quint64 setcode,qint64 level,qint64 lscale,qint64 rscale,qint64 linkMarker,
			quint64 attribute, quint64 race, const Value& atk, const Value& def,const QString& name,const QString& desc); 
		~ClientCard();
		quint64 id;//����
		quint32 ot;//��Ƭ�������
		quint64 alias;//��Ƭ����
		quint64 type;//��Ƭ���
		quint64 setcode;//��Ƭ�ֶ�
		qint64 level;//�ȼ����׼�
		qint64 lscale;//�����
		qint64 rscale;//�����
		qint64 linkMarker;//���ӱ��
		quint64 attribute;//����
		quint64 race;//����
		Value atk;//������
		Value def;//�ر���
		QString name;//��Ƭ����
		QString desc;//�ı�����
	private:
	};
}