#pragma once
#include "DxLib.h"

#define SPEED 10 
// A�L�[��D�L�[���������Ƃ��ɁA�ړ����鋗��
#define TEKICOUNT 22 
// �G�̌� 
#define POSYONCOUNT 20 
// �����S�̌�
#define GAMETIME 36000000

#define HAIKEICOUNT 50
int gameTime; // �Q�[���̃v���C���� 
int startTime; // �Q�[���̃v���C�J�n����
// �\���̃e���v���[�grec1
struct rec1 {
	int x1, y1, x2, y2; // ���[���h���W�ƃX�N���[�����W 
	int oldX1, oldX2; // ���O�̃��[���h���W�ƃX�N���[�����W�@ 
	int w, h; // ���ƍ��� 
	int num; // �C���[�W�̃n���h���ԍ� 
	int handle[4]; // �C���[�W�̃n���h���i�R��ށj 
	int jumpFlag; // �W�����v��Ԃ�\���t���O 
	int HP; // �_�� 
};

// �\���̃e���v���[�grec2 
struct rec2 {
	int x1, y1;   //���[���h���W
	int w, h;     //�r���̕��ƍ���
	int handle;//�C���[�W�̃n���h��
	int flag;
	int HP;
};


// �\���̃e���v���[�grec3 
struct rec3 {
	int x1, y1;
	int w, h;
	int handle;
	int flag;   //�ь�̕\���A��\����ݒ肷��t���O 
};

// �\���̃e���v���[�grec2 
struct rec4 {
	int x1, y1, x2, y2;   //���[���h���W
	int w, h;     //�r���̕��ƍ���
	int handle;//�C���[�W�̃n���h��
	int flag;
};


// �֐��v���g�^�C�v�錾 
void initialize(void); // �������֐��˕ϐ��Ȃǂɏ��߂̒l�����邱��
void process(void); // �����֐� 
void disp(void);  // �\���֐� 
void atari(void); // �����S�̓����蔻��֐� 
void tekiatari(void);
void tekiatari2(void);



