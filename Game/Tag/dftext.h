/*
�����ˣ���������
�������ڣ�2024-6-9
������
*/
#pragma once
#include <QCoreApplication>
namespace GameClient::Tag {
#define TEXT_NONE  QCoreApplication::translate("GameClass","\50\346\227\240\51",nullptr)//���ޣ�
#define TEXT_NA  QCoreApplication::translate("GameClass","\50\116\57\101\51",nullptr)//��N/A��

#define TEXT_ATTRIBUTE_EARTH QCoreApplication::translate("GameClass","\345\234\260",nullptr)//��
#define TEXT_ATTRIBUTE_WATER QCoreApplication::translate("GameClass","\346\260\264",nullptr)//ˮ
#define TEXT_ATTRIBUTE_FIRE QCoreApplication::translate("GameClass","\347\201\253",nullptr)//��
#define TEXT_ATTRIBUTE_WIND QCoreApplication::translate("GameClass","\351\243\216",nullptr)//��
#define TEXT_ATTRIBUTE_LIGHT QCoreApplication::translate("GameClass","\345\205\211",nullptr)//��
#define TEXT_ATTRIBUTE_DARK QCoreApplication::translate("GameClass","\346\232\227",nullptr)//��
#define TEXT_ATTRIBUTE_DEVINE QCoreApplication::translate("GameClass","\347\245\236",nullptr)//��

#define TEXT_RACE_WARRIOR QCoreApplication::translate("GameClass","\346\210\230\345\243\253",nullptr)//սʿ
#define TEXT_RACE_SPELLCASTER QCoreApplication::translate("GameClass","\351\255\224\346\263\225\345\270\210",nullptr)//ħ��ʦ
#define TEXT_RACE_FAIRY QCoreApplication::translate("GameClass","\345\244\251\344\275\277",nullptr)	//��ʹ
#define TEXT_RACE_FIEND QCoreApplication::translate("GameClass","\346\201\266\351\255\224",nullptr)//��ħ
#define TEXT_RACE_ZOMBIE QCoreApplication::translate("GameClass","\344\270\215\346\255\273",nullptr)//����
#define TEXT_RACE_MACHINE QCoreApplication::translate("GameClass","\346\234\272\346\242\260",nullptr)//��е
#define TEXT_RACE_AQUA QCoreApplication::translate("GameClass","\346\260\264",nullptr)//ˮ
#define TEXT_RACE_PYRO QCoreApplication::translate("GameClass","\347\202\216",nullptr)//��
#define TEXT_RACE_ROCK QCoreApplication::translate("GameClass","\345\262\251\347\237\263",nullptr)//��ʯ
#define TEXT_RACE_WINDBEAST QCoreApplication::translate("GameClass","\351\270\237\345\205\275",nullptr) // ����
#define TEXT_RACE_PLANT QCoreApplication::translate("GameClass","\346\244\215\347\211\251",nullptr) // ֲ��
#define TEXT_RACE_INSECT QCoreApplication::translate("GameClass","\346\230\206\350\231\253",nullptr) // ����
#define TEXT_RACE_THUNDER QCoreApplication::translate("GameClass","\351\233\267",nullptr) // ��
#define TEXT_RACE_DRAGON QCoreApplication::translate("GameClass","\351\276\231",nullptr) // ��
#define TEXT_RACE_BEAST QCoreApplication::translate("GameClass","\345\205\275",nullptr) // ��
#define TEXT_RACE_BEASTWARRIOR QCoreApplication::translate("GameClass","\345\205\275\346\210\230\345\243\253",nullptr) // ��սʿ
#define TEXT_RACE_DINOSAUR QCoreApplication::translate("GameClass","\346\201\220\351\276\231",nullptr) // ����
#define TEXT_RACE_FISH QCoreApplication::translate("GameClass","\351\261\274",nullptr) // ��
#define TEXT_RACE_SEASERPENT QCoreApplication::translate("GameClass","\346\265\267\351\276\231",nullptr) // ����
#define TEXT_RACE_REPTILE QCoreApplication::translate("GameClass","\347\210\254\350\231\253\347\261\273",nullptr) // ������
#define TEXT_RACE_PSYCHO QCoreApplication::translate("GameClass","\345\277\265\345\212\250\345\212\233",nullptr) // ���
#define TEXT_RACE_DEVINE QCoreApplication::translate("GameClass","\345\271\273\347\245\236\345\205\275",nullptr) // ������
#define TEXT_RACE_CREATORGOD QCoreApplication::translate("GameClass","\345\210\233\351\200\240\347\245\236",nullptr) // ������
#define TEXT_RACE_WYRM QCoreApplication::translate("GameClass","\345\271\273\351\276\231",nullptr) // ����
#define TEXT_RACE_CYBERSE QCoreApplication::translate("GameClass","\347\224\265\345\255\220\347\225\214",nullptr) // ���ӽ�


#define TEXT_TYPE_MONSTER QCoreApplication::translate("GameClass","\346\200\252\345\205\275",nullptr)//����
#define TEXT_TYPE_SPELL QCoreApplication::translate("GameClass","\351\255\224\346\263\225",nullptr)//ħ��
#define TEXT_TYPE_TRAP QCoreApplication::translate("GameClass","\351\231\267\351\230\261",nullptr)//����
#define TEXT_TYPE_NORMAL QCoreApplication::translate("GameClass", "\351\200\232\345\270\270", nullptr)  // ͨ��
#define TEXT_TYPE_EFFECT QCoreApplication::translate("GameClass", "\346\225\210\346\236\234", nullptr)  // Ч��
#define TEXT_TYPE_FUSION QCoreApplication::translate("GameClass", "\350\236\215\345\220\210", nullptr)  // �ں�
#define TEXT_TYPE_RITUAL QCoreApplication::translate("GameClass", "\344\273\252\345\274\217", nullptr)  // ��ʽ
#define TEXT_TYPE_TRAPMONSTER QCoreApplication::translate("GameClass", "\351\231\267\351\230\261\346\200\252\345\205\275", nullptr)  // �������
#define TEXT_TYPE_SPIRIT QCoreApplication::translate("GameClass", "\347\201\265\351\255\202", nullptr)  // ���
#define TEXT_TYPE_UNION QCoreApplication::translate("GameClass", "\345\220\214\347\233\237", nullptr)  // ͬ��
#define TEXT_TYPE_DUAL QCoreApplication::translate("GameClass", "\344\272\214\351\207\215", nullptr)  // ����
#define TEXT_TYPE_TUNER QCoreApplication::translate("GameClass", "\350\260\203\346\225\264", nullptr)  // ����
#define TEXT_TYPE_SYNCHRO QCoreApplication::translate("GameClass", "\345\220\214\350\260\203", nullptr)  // ͬ��
#define TEXT_TYPE_TOKEN QCoreApplication::translate("GameClass", "\350\241\215\347\224\237\347\211\251", nullptr)  // ������
#define TEXT_TYPE_QUICKPLAY QCoreApplication::translate("GameClass", "\351\200\237\346\224\273", nullptr)  // �ٹ�
#define TEXT_TYPE_CONTINUOUS QCoreApplication::translate("GameClass", "\\346\260\270\347\273\255", nullptr)  // ����
#define TEXT_TYPE_EQUIP QCoreApplication::translate("GameClass", "\350\243\205\345\244\207", nullptr)  // װ��
#define TEXT_TYPE_FIELD QCoreApplication::translate("GameClass", "\345\234\272\345\234\260", nullptr)  // ����
#define TEXT_TYPE_COUNTER QCoreApplication::translate("GameClass", "\345\217\215\345\207\273", nullptr)  // ����
#define TEXT_TYPE_FLIP QCoreApplication::translate("GameClass", "\345\217\215\350\275\254", nullptr)  // ��ת
#define TEXT_TYPE_TOON QCoreApplication::translate("GameClass", "\345\215\241\351\200\232", nullptr)  // ��ͨ
#define TEXT_TYPE_XYZ QCoreApplication::translate("GameClass", "\350\266\205\351\207\217", nullptr)  // ����
#define TEXT_TYPE_PENDULUM QCoreApplication::translate("GameClass", "\347\201\265\346\221\206", nullptr)  // ���
#define TEXT_TYPE_SPSUMMON QCoreApplication::translate("GameClass", "\347\211\271\346\256\212\345\217\254\345\224\244", nullptr)  // �����ٻ�
#define TEXT_TYPE_LINK QCoreApplication::translate("GameClass", "\351\223\276\346\216\245", nullptr)  // ����



}