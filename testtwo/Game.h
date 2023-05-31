#pragma once
#include "DxLib.h"

#define SPEED 10 
// AキーとDキーを押したときに、移動する距離
#define TEKICOUNT 22 
// 敵の個数 
#define POSYONCOUNT 20 
// リンゴの個数
#define GAMETIME 36000000

#define HAIKEICOUNT 50
int gameTime; // ゲームのプレイ時間 
int startTime; // ゲームのプレイ開始時間
// 構造体テンプレートrec1
struct rec1 {
	int x1, y1, x2, y2; // ワールド座標とスクリーン座標 
	int oldX1, oldX2; // 一つ手前のワールド座標とスクリーン座標　 
	int w, h; // 幅と高さ 
	int num; // イメージのハンドル番号 
	int handle[4]; // イメージのハンドル（３種類） 
	int jumpFlag; // ジャンプ状態を表すフラグ 
	int HP; // 点数 
};

// 構造体テンプレートrec2 
struct rec2 {
	int x1, y1;   //ワールド座標
	int w, h;     //ビルの幅と高さ
	int handle;//イメージのハンドル
	int flag;
	int HP;
};


// 構造体テンプレートrec3 
struct rec3 {
	int x1, y1;
	int w, h;
	int handle;
	int flag;   //林檎の表示、非表示を設定するフラグ 
};

// 構造体テンプレートrec2 
struct rec4 {
	int x1, y1, x2, y2;   //ワールド座標
	int w, h;     //ビルの幅と高さ
	int handle;//イメージのハンドル
	int flag;
};


// 関数プロトタイプ宣言 
void initialize(void); // 初期化関数⇒変数などに初めの値を入れること
void process(void); // 処理関数 
void disp(void);  // 表示関数 
void atari(void); // リンゴの当たり判定関数 
void tekiatari(void);
void tekiatari2(void);



