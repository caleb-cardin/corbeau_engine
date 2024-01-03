// Created by cabo_ on 1/3/2024.
//

export module Vector;


export namespace corbeau {

    struct Vector3 {
        float x, y, z;

        Vector3() = default;

        Vector3(const float a, const float b, const float c) : x(a), y(b), z(c) {}


        auto operator[](const int index)->float& {return (&x)[index];}
        auto operator[](const int index)const->const float& {return (&x)[index];}


        auto operator*=(const float scalar)->Vector3&
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            return *this;
        }
        auto operator/=(const float scalar)->Vector3&
        {
            const auto s = 1.f / scalar;
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }
    };

    auto operator+(const Vector3& v_0, const Vector3& v_1)->Vector3
    {
        return {v_0.x + v_1.x, v_0.y + v_1.y, v_0.z + v_1.z};
    }
    auto operator-(const Vector3& v_0, const Vector3& v_1)->Vector3
    {
        return {v_0.x - v_1.x, v_0.y - v_1.y, v_0.z - v_1.z};
    }

    auto operator*(const Vector3& v_0, const float scalar)->Vector3
    {
        return {v_0.x * scalar, v_0.y - scalar, v_0.z - scalar};
    }
    auto operator/(const Vector3& v_0, const float scalar)->Vector3
    {
        const auto s = 1.f / scalar;
        return {v_0.x * s, v_0.y - s, v_0.z - s};
    }
}