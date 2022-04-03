#include <Arduino.h>

class Vector2
{
    public:
    float x;
    float y;
    Vector2(float x, float y): x(x), y(y) {}

    Vector2& operator+=(Vector2& v)
    {
        this->x += v.x;
        this->y += v.y;
        return *this;
    }

    float magnitude()
    {
        return sqrt(x*x + y*y);
    }
};

Vector2 operator+(Vector2 a, Vector2 b)
{
    return Vector2(a.x + b.x, a.y + b.y);
}



float alpha(float r1, float r2, Vector2 B)
{
        /* Explanation xd
    A = r1 * Vector2(cos(alpha), sin(alpha))
    gamma = alpha + beta
    B = A + r2 * Vector2(cos(gamma), sin(gamma))

       (r1 * cos(alpha) + r2 * cos(gamma))
    B={                                   }
       (r2 * sin(alpha) + r2 * sin(gamma))

    r2 * cos(gamma) = B.x - r1 * sin(alpha)
    r2 * sin(gamma) = B.y - r1 * sin(alpha)

    squaring and adding to remove cos(alpha) and sin(alpha)

    r2^2 = (B.x - r1 * cos(alpha))^2 + (B.y - r1 * sin(alpha))^1
    r2^2 = B.x^2 - 2 * B.x * r1 * cos(alpha) + B.y^2 - 2 * B.y * r1 *sin(gamma) + r1^2

    2 * B.x * r1 * cos(alpha) + 2 * B.y * r1 * sin(alpha) = B.x^2 + B.y^2 + r1^2 - r1^2

    a = 2 * B.x * r1
    b = 2 * B.y * r1
    c = B.x^2 + B.y^2 + r1^2 + r2^2

    a * cos(alpha) + b * sin(alpha) = c

    we suppose that:
    a = cos(delta) and b = sin(delta)
    and so:
    rho = sqrt(a^2 + b^2)
    then:
    (a/rho) * cos(alpha) + (b/rho) * sin(alpha) = c/rho
    that ecuation would be:
    cos(delta) * cos(alpha) + sin(delta) * sin(alpha) = c
    and so:
    cos(alpha - delta) = c
    alpha - delta = arccos(c)

    going back to the other ecuation:

    delta = atan2((b/rho), (a/rho))

    alpha - delta = arccos(c/rho)
    alpha = delta + arccos(c/rho)
    */
    float a = 2 * B.x * r1;
    float b = 2 * B.y * r1;
    float c = B.x * B.x + B.y * B.y + r1 * r1 - r2 * r2;

    float rho = sqrt(a*a + b*b);
    float delta = atan2(b/rho, a/rho);

    Serial.print("c: ");
    Serial.print(c);
    Serial.print(", rho: ");
    Serial.print(rho);
    Serial.println();
    float _alpha = delta - acos(c/rho);

    if(_alpha > 0) // We want alpha to be negative so that it doesnt got though the roof
        _alpha *= -1;
    return _alpha;
}

float beta(float alpha, float r1, float r2, Vector2 B)
{
    /*
    Knowing that: r2 * cos(gamma) = B.x - r1 * cos(alpha) then:
    then:
    cos(gamma) = (B.x - r1 * cos(alpha)) / r2
    gamma = arccos((B.x - r1 * cos(alpha)) / r2) 
    */

   float _gamma = atan2(B.y - r1 * sin(alpha), B.x - r1 * cos(alpha));
    return _gamma - alpha;
}