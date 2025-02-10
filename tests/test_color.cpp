#include "../src/color.h"
#include <sstream>
#include <cassert>

void test_write_color() {
    std::ostringstream output;

    // Test case 1: Black (0,0,0) -> "0 0 0"
    
    write_color(output, color(0.0, 0.0, 0.0));
    assert(output.str() == "0 0 0\n");
    output.str(""); output.clear(); // Reset output stream

    // Test case 2: White (1,1,1) -> "255 255 255"
    write_color(output, color(1.0, 1.0, 1.0));
    assert(output.str() == "255 255 255\n");
    output.str(""); output.clear();

    // Test case 3: Red (1,0,0) -> "255 0 0"
    write_color(output, color(1.0, 0.0, 0.0));
    assert(output.str() == "255 0 0\n");
    output.str(""); output.clear();

    // Test case 4: Green (0,1,0) -> "0 255 0"
    write_color(output, color(0.0, 1.0, 0.0));
    assert(output.str() == "0 255 0\n");
    output.str(""); output.clear();

    // Test case 5: Blue (0,0,1) -> "0 0 255"
    write_color(output, color(0.0, 0.0, 1.0));
    assert(output.str() == "0 0 255\n");
    output.str(""); output.clear();

    // Test case 6: Mid-gray (0.5, 0.5, 0.5) -> "127 127 127"
    write_color(output, color(0.5, 0.5, 0.5));
    assert(output.str() == "127 127 127\n");
    output.str(""); output.clear();

    // Test case 7: Arbitrary values
    write_color(output, color(0.25, 0.75, 0.1));
    assert(output.str() == "63 191 25\n"); // (255.999 * 0.25 = 63, etc.)
    output.str(""); output.clear();

    std::cout << "All tests passed!\n";
}

int main() {
    test_write_color();
    return 0;
}