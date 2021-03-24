/*
class Point
{
public:
    Point(float x, float y); // 直交座標
    Point(float r, float t); // 曲座標
};
int main()
{
    Point p(1.0, 3.0); 
    // どっちのコンストラクタを呼んでいいかわからないのでコンパイルエラー
}
*/

class Point
{
public:
    // construct a point from Cart coord
    static Point createFromCart(float x, float y); 
    // construct a point from Polar coord
    static Point createFromPolar(float r, float t);

private:
    Point(float x, float y); // Cart coord float x, y; // Cart coord
};
int main()
{
    Point p1 = Point::createFromCart(1.0, 3.0);
}