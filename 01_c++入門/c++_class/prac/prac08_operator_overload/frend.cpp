#include <iostream>

/***********************/
/* クラスExampleの定義 */
/***********************/
class Example
{
private:
	int x;

public:
	int y;
	void set(int, int);
	friend void fun1(Example &);
	friend class Example_freiend;
};

/***************************************/
/* クラスExampleのフレンドクラスの定義 */
/***************************************/
class Example_freiend
{
public:
	void fun3(Example &data)
	{
		std::cout << "フレンドクラス x " << data.x << " y " << data.y << std::endl;
	}
};

void fun2(Example &);
void Example::set(int a, int b)
{
	x = a;
	this->y = b; // y = b と同じ
	std::cout << "メンバー関数 x " << x << " y " << y << std::endl;
}

/****************/
/* フレンド関数 */
/****************/
void fun1(Example &data)
{
	std::cout << "フレンド関数 x " << data.x << " y " << data.y << std::endl;
}

/**************/
/* 普通の関数 */
/**************/
void fun2(Example &data)
{
	std::cout << "通常の関数 x ??"
			  << " y " << data.y << std::endl; // xにはアクセスできない
}

/************/
/* main関数 */
/************/
int main()
{
	Example data;	
	Example_freiend data_freiend;

	data.set(10, 20); // メンバー関数の呼び出し．ピリオドに注意
	fun1(data);		  // フレンド関数の呼び出し
	fun2(data);		  // 普通の関数の呼び出し
	data_freiend.fun3(data); // クラスExample1のメンバー関数の呼び出し

	return 0;
}
