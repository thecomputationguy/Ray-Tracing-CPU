#include "../src/vec3.h"
#include <iostream>
#include <cassert>

void test_vec3() {
    // Test default constructor
    vec3 v1;
    assert(v1.x() == 0 && v1.y() == 0 && v1.z() == 0);

    // Test parameterized constructor
    vec3 v2(1.0, 2.0, 3.0);
    assert(v2.x() == 1.0 && v2.y() == 2.0 && v2.z() == 3.0);

    // Test negation
    vec3 v3 = -v2;
    assert(v3.x() == -1.0 && v3.y() == -2.0 && v3.z() == -3.0);

    // Test addition
    vec3 v4 = v2 + vec3(2.0, 3.0, 4.0);
    assert(v4.x() == 3.0 && v4.y() == 5.0 && v4.z() == 7.0);

    // Test subtraction
    vec3 v5 = v4 - v2;
    assert(v5.x() == 2.0 && v5.y() == 3.0 && v5.z() == 4.0);

    // Test scalar multiplication
    vec3 v6 = v2 * 2.0;
    assert(v6.x() == 2.0 && v6.y() == 4.0 && v6.z() == 6.0);

    // Test dot product
    double dot_product = v2.dot(vec3(2.0, 0.0, 0.0));
    assert(dot_product == 2.0);

    // Test cross product
    vec3 v7 = vec3(1, 0, 0).cross(vec3(0, 1, 0));
    assert(v7.x() == 0 && v7.y() == 0 && v7.z() == 1);

    // Test length
    assert(vec3(3, 4, 0).length() == 5.0);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_vec3();
    return 0;
}
