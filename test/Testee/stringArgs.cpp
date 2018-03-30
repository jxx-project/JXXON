#include <iostream>

template<const char* Arg = "cool">
class Sample
{
public:
    static void print()
    {
        std::cout << Arg << std::endl;
    }
};

constexpr char HELLO_WORLD[] = "hello world";

int main(int argc, char* argv[])
{
    Sample<HELLO_WORLD>::print();
    return 0;
}
