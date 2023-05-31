#include "Game.h"  //main.hを組み込むように書き換える

struct rec1 pl; // 構造体テンプレートrec1を使って、plという変数で使用する。 
struct rec2 tk[TEKICOUNT]; // 構造体テンプレートrec2を使って、blという変数で使用する。
struct rec3 po[POSYONCOUNT];// 構造体テンプレートrec3を使って、apという変数で使用する。
struct rec4 si[HAIKEICOUNT];

bool gameOver = false; //ゲームオーバーフラグ
bool gameClear = false;//ゲームクリアフラグ


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}


	initialize(); // initialize関数を実行する。 
	process(); // process関数を実行する。 
	if (gameClear == true || gameOver == true) //gameClearかgameOverのフラグがtrueになったら
	{
		WaitKey();
	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

void initialize(void)
{
	int SHandle = LoadSoundMem("images/sound.MP3");
	PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);


	pl.x1 = 100; // プレイヤーの初期位置の設定 
	pl.y1 = 330; // ｙ座標は、地面の座標を400と決めて、 
				// 高さと足して400になるようにする。 
	pl.x2 = pl.x1; // スクリーン座標の初期値は、ワールド座標と同じ。 
	pl.y2 = pl.y1;
	pl.w = 60; // プレイヤーの幅（高さより少し小さい方が形が良い。 
	pl.h = 70; // プレイヤーの高さ(ｙ座標と足して地面の値になるように) 
	pl.num = 0; //　ハンドル番号は、0、1、2の繰り返し。初期値は0 
	// ハンドルは３つの配列。それぞれのイメージを 
	// メモリにロードして、設定する。
	pl.handle[0] = LoadGraph("images/korinku.png"); 
	pl.handle[1] = LoadGraph("images/korinku1.png"); 
	pl.handle[2] = LoadGraph("images/korinku2.png"); 
	pl.handle[3] = LoadGraph("images/korinku3.png");
	pl.jumpFlag = 0; // ジャンプ状態を表すフラグ。初期値は0 
	pl.HP = 10000; //HPの初期化


	int i;
	int handle1 = LoadGraph("images/zerudateki1.png");
	int handle2 = LoadGraph("images/zerudateki2.png");
	int handle3 = LoadGraph("images/zerudateki3.png");
	int handle4 = LoadGraph("images/zerudateki4.png");
	int handle5 = LoadGraph("images/zerudateki5.png");
	int handle6 = LoadGraph("images/zerudateki6.png");
	int handle7 = LoadGraph("images/zerudateki7.png");
	int handle8 = LoadGraph("images/zerudateki8.png");
	int handle9 = LoadGraph("images/zerudateki9.png");
	int handle11 = LoadGraph("images/zerudateki11.png");
	int handle12 = LoadGraph("images/zerudateki12.png");
	int handle13 = LoadGraph("images/zerudateki13.png");
	int handle15 = LoadGraph("images/zerudateki15.png");
	int handle16 = LoadGraph("images/zerudateki16.png");
	int handle17 = LoadGraph("images/zerudateki17.png");
	int handle18 = LoadGraph("images/zerudateki18.png");
	int handle19 = LoadGraph("images/zerudateki19.png");
	int handle20 = LoadGraph("images/zerudateki20.png");
	int handle21 = LoadGraph("images/zerudateki21.png");
	int handle22 = LoadGraph("images/zerudateki22.png");
	int handle23 = LoadGraph("images/ganonn.png");
	int handle24 = LoadGraph("images/zerudahime.png");
	// 敵のイメージをメモリに読み込んで、ハンドル番号をつける。
	for (i = 0; i < TEKICOUNT; i++)
		
	{
		 
		if (i == 0)
			// 最初の１個は、プレイヤーの右に座標を固定する。 
		{
			tk[i].x1 = 200;
		}
		else if (i == 20)

		{
			tk[i].x1 = tk[19].x1 + tk[19].w + 100;
		}
		else if (i == 21)

		{
			tk[i].x1 = tk[20].x1 + tk[20].w;
		}
		else
			// それ以外は、１個前の敵の右端(x座標+w) + 最低離す距離 + 乱数により離す距離 
		{
			tk[i].x1 = tk[i - 1].x1 + tk[i - 1].w + 100;// +GetRand(100);
		}
		tk[i].y1 = 290;
		tk[i].w = 40;
		tk[i].h = 400 - tk[i].y1;
		tk[i].flag = 1;
		int kinds = i;
		// i番目のビルのハンドルに、ビルのイメージのハンドル番号を設定する。 
		if (kinds == 0)
		{
			tk[i].HP = 1;
			tk[i].handle = handle1;

		}
		if (kinds == 1)
		{
			tk[i].HP = 2;
			tk[i].handle = handle2;

		}
		if (kinds == 2)
		{
			tk[i].HP = 3;
			tk[i].handle = handle3;

		}
		if (kinds == 3)
		{
			tk[i].HP = 4;
			tk[i].handle = handle4;

		}
		if (kinds == 4)
		{
			tk[i].HP = 5;
			tk[i].handle = handle5;

		}
		if (kinds == 5)
		{
			tk[i].HP = 6;
			tk[i].handle = handle6;

		}
		if (kinds == 6)
		{
			tk[i].HP = 7;
			tk[i].handle = handle7;

		}
		if (kinds == 7)
		{
			tk[i].HP = 8;
			tk[i].handle = handle8;

		}
		if (kinds == 8)
		{
			tk[i].HP = 9;
			tk[i].handle = handle9;

		}
		if (kinds == 9)
		{
			tk[i].HP = 10;
			tk[i].handle = handle11;

		}
		if (kinds == 10)
		{
			tk[i].HP = 11;
			tk[i].handle = handle12;

		}
		if (kinds == 11)
		{
			tk[i].HP = 12;
			tk[i].handle = handle13;

		}
		if (kinds == 12)
		{
			tk[i].HP = 13;
			tk[i].handle = handle15;

		}
		if (kinds == 13)
		{
			tk[i].HP = 14;
			tk[i].handle = handle16;

		}
		if (kinds == 14)
		{
			tk[i].HP = 15;
			tk[i].handle = handle17;

		}
		if (kinds == 15)
		{
			tk[i].HP = 16;
			tk[i].handle = handle18;

		}
		if (kinds == 16)
		{
			tk[i].HP = 17;
			tk[i].handle = handle19;

		}
		if (kinds == 17)
		{
			tk[i].HP = 18;
			tk[i].handle = handle20;

		}
		if (kinds == 18)
		{
			tk[i].HP = 19;
			tk[i].handle = handle21;

		}
		if (kinds == 19)
		{
			tk[i].HP = 20;
			tk[i].handle = handle22;
		}
		if (kinds == 20)
		{
			tk[i].HP = 21;
			tk[i].handle = handle23;
		}
		if (kinds == 21)
		{
			tk[21].HP = 0;
			tk[21].handle = handle24;
		}
	}

	int handle = LoadGraph("images/item.png");
	// ポーションのイメージをメモリにロードして、ハンドル番号をつける。 
	for (i = 0; i < POSYONCOUNT; i++)
		// リンゴの数50個繰り返し 
	{
		if (i == 0)
			// 最初のポーションはプレイヤーの右側で固定 
		{
			po[0].x1 = 240;
		}
		else
			
		{
			// １つ前のポーションの右端(x1 + w) + 最低間隔 + 乱数幅 
			po[i].x1 = po[i - 1].x1 + po[i - 1].w + 20 + GetRand(180);
		}

		po[i].w = 30; 
		po[i].h = po[i].w;
		po[i].y1 = 100 + GetRand(200); 
		po[i].flag = 1; 
		po[i].handle = handle;
	
	}

	int handlee = LoadGraph("images/hairarusiro.png");
	
	for (i = 0; i < HAIKEICOUNT; i++)
		// ハイラル城の数50個繰り返し 
	{
		if (i == 0)
			// 最初のハイラル城はプレイヤーの右側で固定 
		{
			si[0].x1 = 0;
		}
		else
			
		{
			// １つ前のハイラル城の右端(x1 + w) + 最低間隔 + 乱数幅 
			si[i].x1 = si[i].x1 + si[i].w + si[i - 1].x1 + si[i - 1].w;// +si[i - 1].x1 + si[i - 1].w;//+ GetRand(180);
		}

		si[i].w = 700;
		si[i].h = 1200 - si[i].w;
		si[i].y1 = 0;
		si[i].flag = 1; 
		si[i].handle = handlee;

	}
}

void process(void)
{


	disp(); // まずは表示 

	int esc = 0; // escapeキーのフラグ 
	int upSpeed = 0; // ジャンプ中に上に上がるスピード
	gameTime = 0; // ゲームのプレイ時間 
	startTime = GetNowCount(); // ゲームのプレイ開始時間
	while (esc == 0 && gameOver == false && gameClear == false) // escapeキーを押すかgameOverまで繰り返し 
	{
		int left = 0; // Aキーのフラグ 
		int right = 0; //Dキーのフラグ 
		int up = 0; // Wキーのフラグ 
		int st = 0;//Sキーのフラグ

		while (left == 0 && right == 0 && esc == 0 && up == 0 && st == 0 && gameOver == false && gameClear == false)
			// escapeキーかAキーかDキーか WキーかSキーを同時に押すかgameOverまで繰り返し		
		{
			gameTime = GetNowCount() - startTime;
			if (gameTime > GAMETIME)
				// プレイ時間がゲーム終了時間を超えたら 
			{
				gameOver = true;
			}
			if (pl.HP <= 0)//プレイヤーの体力が0になったら
			{

				gameOver = true;
			}
			if (tk[20].flag <= 0)//最後のボスガノンドロフをたおしたら
			{
				gameClear = true;
			}

			esc = CheckHitKey(KEY_INPUT_ESCAPE);
	
			left = CheckHitKey(KEY_INPUT_A);

			right = CheckHitKey(KEY_INPUT_D);

			up = CheckHitKey(KEY_INPUT_W);
		
			st = CheckHitKey(KEY_INPUT_S);


			if (pl.jumpFlag == 1)
				//ジャンプ中であれば
			{
				pl.y1 -= upSpeed;//プレイヤーのy座標を上下するスピード分減らす。
				pl.y2 -= upSpeed;

				if (upSpeed < 0)
					// ジャンプが下降中であれば、 
				{
					tekiatari();
				}

				atari(); // 当たり判定関数の呼び出し
				disp(); // y座標が変化したので表示する。

				if (pl.y1 + pl.h >= 400)
					// 地面まで下りてきたら 
				{
					// ジャンプの終了 
					pl.jumpFlag = 0;
				}
				else
				{
					
					upSpeed--;
				}
			}

			WaitTimer(50); // 時間稼ぎ 
		}

		//Aキーが押されていれば 
		if (left == 1)
		{
			// ハンドル番号の切り替え(0→1→2) 
			pl.num = pl.num + 0;

			// ワールド座標を左へ移動 
			pl.x1 -= SPEED;
			// スクリーン座標が、止めたい左の座標＋SPEED以上ならば 
			if (pl.x2 >= 20 + SPEED)
			{
				pl.x2 -= SPEED;
				atari();
				tekiatari();
			}
		}

		// Dキーが押されていれば 
		if (right == 1)
		{
			// ハンドル番号の切り替え(0→1→2) 
			pl.num = pl.num + 0;


			// ワールド座標を右へ移動 
			pl.x1 += SPEED;
			// スクリーン座標が止めたい右端 - プレイヤーの幅 - SPEED以下ならば 
			if (pl.x2 <= 620 - pl.w - SPEED)
			{
				// スクリーン座標を右へ移動 
				pl.x2 += SPEED;
				atari();
				tekiatari();
			}

		}

		//Sキーをお押したら攻撃できる
		if (st == 1)
		{
			pl.num = (pl.num + 2) % 3;
			tekiatari2();
		}

		if (up == 1)
			// ↑キーを押していたら 
		{
			if (pl.jumpFlag == 0) //⇒これがないと2段ジャンプ(無限ジャンプ)になる
				// ジャンプ中でなければ 
			{
				pl.jumpFlag = 1;
				// ジャンプ中にする。
				upSpeed = 15 + GetRand(10);
				// 上下するスピードの初期値を最低15 最高30に乱数で設定 
			}
		}

		disp();
		// 表示 
	}
}

void disp(void)
{
	int i; //繰り返し変数の定義
	ClearDrawScreen(); // 画面のクリア 

	for (i = 0; i < HAIKEICOUNT; i++)
		// リンゴの個数繰り返し 
	{
		if (si[i].flag == 1)
			// ハイラル城の表示フラグが１（表示）ならば 
		{
			int x1 = si[i].x1 - pl.x1 + pl.x2;
	
			int y1 = si[i].y1;

			int x2 = x1 + si[i].w;
			
			int y2 = y1 + si[i].h;

			DrawExtendGraph(x1, y1, x2, y2, si[i].handle, TRUE);
			; 
		}
	}


	//敵の表示
	for (i = 0; i < TEKICOUNT; i++)
		//敵の個数繰り返し 
	{
		if (tk[i].flag == 1)
		{
			int x1 = tk[i].x1 - pl.x1 + pl.x2;
			
			int y1 = tk[i].y1;
	
			int x2 = x1 + tk[i].w;
		
			int y2 = y1 + tk[i].h;


			DrawExtendGraph(x1, y1, x2, y2, tk[i].handle, TRUE);
		}
	}

	//ポーションの表示
	for (i = 0; i < POSYONCOUNT; i++)
		// ポーションの個数繰り返し 
	{
		if (po[i].flag == 1)
			// ポーションの表示フラグが１（表示）ならば 
		{
			int x1 = po[i].x1 - pl.x1 + pl.x2;

			int y1 = po[i].y1;
			
			int x2 = x1 + po[i].w;
			
			int y2 = y1 + po[i].h;
			
			DrawExtendGraph(x1, y1, x2, y2, po[i].handle, TRUE);
		 
		}
	}

	// 主人公の表示 
	int x1 = pl.x2; // 左上のｘ座標 
	int y1 = pl.y2; // 左上のｙ座標 
	int x2 = pl.x2 + pl.w; // 右下のｘ座標 
	int y2 = pl.y2 + pl.h; // 右下のｙ座標 
	int handle = pl.handle[pl.num]; // ハンドルの指定 
	DrawExtendGraph(x1, y1, x2, y2, handle, TRUE);
	

	if (gameOver == true)
		// gameOverフラグがtureならば 
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "GameOver(x_x)");
		
	}
	if (gameClear == true)
		// gameClearフラグがtrueならば 
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "GameClear(≧∇≦)");
	}

	DrawFormatString(0, 0, GetColor(0, 0, 255), "Dキー : 右に移動");
	DrawFormatString(0, 20, GetColor(0, 0, 255), "Aキー : 左に移動");
	DrawFormatString(0, 40, GetColor(0, 0, 255), "Wキー : ジャンプする");
	DrawFormatString(0, 60, GetColor(0, 0, 255), "Sキー : 攻撃する");
	DrawFormatString(0, 80, GetColor(255, 255, 0), "迫りくる敵を倒して時間以内にゼルダ姫を救い出そう!!");
	DrawFormatString(0, 100, GetColor(255, 255, 255), "見えない敵もいるからHPをしっかり確認しよう!!");
	DrawFormatString(0, 120, GetColor(0, 255, 0), "ポーションをゲットするとHPを回復できるぞ!!");

	DrawFormatString(0, 450, GetColor(255, 0, 0), "HP : %6d", pl.HP);

	DrawFormatString(400, 450, GetColor(255, 0, 0), "TIME : %6d", gameTime);

}

void atari(void)
{
	int i;
	int x1 = pl.x1 + pl.w / 2; // プレイヤーの中心のｘ座標を求める。 
	int y1 = pl.y1 + pl.h / 2; // プレイヤーの中心のｙ座標を求める。 

	for (i = 0; i < POSYONCOUNT; i++)
		// ポーションの個数繰り返し 
	{
		if (po[i].flag == 1)
			// ポーションが表示されていれば 
		{
			int x2 = po[i].x1 + po[i].w / 2; // i番目のポーションの中心のx座標を求める。 
			int y2 = po[i].y1 + po[i].h / 2; // i番目のポーションの中心のy座標を求める。 
			int kyori2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			// プレイヤーとポーションの距離の２乗を求める。⇒距離を出すには√が必要で√の文は長く、処理に時間がかかるから 
			int r = pl.w / 2 + po[i].w / 2;
			// プレイヤーの幅の半分とi番目のポーションの幅の半分を足す。 
			if (kyori2 < r * r)
				// 距離の２条が、半径の２乗よりも小さければ 
			{
				po[i].flag = 0;
				// i番目のポーションの表示を消す。
				pl.HP += 200 - po[i].w;
			}
		}
	}
}

void tekiatari(void)
{
	int i;
	int x1 = pl.x1 + pl.w / 2; // プレイヤーの中心のｘ座標を求める。 
	int y1 = pl.y1 + pl.h / 2; // プレイヤーの中心のｙ座標を求める。 

	for (i = 0; i < TEKICOUNT; i++)
		// 敵の個数繰り返し 
	{
		if (tk[i].flag == 1)
			// 敵が表示されていれば 
		{
			int x2 = tk[i].x1 + tk[i].w / 2; // i番目の敵の中心のx座標を求める。 
			int y2 = tk[i].y1 + tk[i].h / 2; // i番目の敵の中心のy座標を求める。 
			int kyori2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			// プレイヤーと敵の距離の２乗を求める。⇒距離を出すには√が必要で√の文は長く、処理に時間がかかるから 
			int r = pl.w / 2 + tk[i].w / 2;
			// プレイヤーの幅の半分とi番目の敵の幅の半分を足す。 
			if (kyori2 < r * r)
				// 距離の２条が、半径の２乗よりも小さければ 
			{
				pl.HP -= 200 - tk[i].HP;
			}
		}
	}
}

void tekiatari2(void)
{
	int SHandle1 = LoadSoundMem("images/soad.MP3");
	SHandle1 = PlaySoundMem(SHandle1, DX_PLAYTYPE_BACK);
	int i;
	int x1 = pl.x1 + pl.w / 2; // プレイヤーの中心のｘ座標を求める。 
	int y1 = pl.y1 + pl.h / 2; // プレイヤーの中心のｙ座標を求める。 

	for (i = 0; i < TEKICOUNT; i++)
		// 敵の個数繰り返し 
	{
		if (tk[i].flag == 1)
			// 敵が表示されていれば 
		{
			int x2 = tk[i].x1 + tk[i].w / 2; // i番目の敵の中心のx座標を求める。 
			int y2 = tk[i].y1 + tk[i].h / 2; // i番目の敵の中心のy座標を求める。 
			int kyori2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			// プレイヤーと敵の距離の２乗を求める。⇒距離を出すには√が必要で√の文は長く、処理に時間がかかるから 
			int r = pl.w / 2 + tk[i].w / 2;
			// プレイヤーの幅の半分とi番目の敵の幅の半分を足す。 
			if (kyori2 < r * r)
				// 距離の２条が、半径の２乗よりも小さければ 
			{
				tk[i].flag = 0;
				tk[21].flag = 1;
			}
		}
	}
}
