#include <coroutine>
#include <iostream>

class Prime
{
public:
    struct Generator;

    static Generator GetGenerator(size_t begin = 0)
    {
        for (;; ++begin)
        {
            if (IsPrime(begin)) co_yield begin;
        }
    }

    struct Generator
    {
        struct promise_type;
        using HandleType = std::coroutine_handle<promise_type>;

        struct promise_type
        {
            Generator get_return_object() noexcept
            {
                return Generator{ HandleType::from_promise(*this) };
            }

            std::suspend_always initial_suspend() noexcept
            {
                return {};
            }

            std::suspend_never final_suspend() noexcept
            {
                return {};
            }

            std::suspend_always yield_value(size_t value) noexcept
            {
                this->value = value;
                return {};
            }

            void unhandled_exception() {}

            size_t value{};
        };

        HandleType handle;

        Generator(HandleType handle) : handle(handle){};

        size_t operator()()
        {
            handle.resume();
            return handle.promise().value;
        }
    };

private:
    static bool IsPrime(size_t number)
    {
        if (number < 2) return false;

        for (uint32_t i = 2; i * i <= number; ++i)
        {
            if (number % i == 0) return false;
        }
        return true;
    }
};

int main(int argc, char const* argv[])
{
    Prime::Generator&& generator = Prime::GetGenerator();

    for (size_t i = 0; i < 100; i++)
    {
        std::cout << generator() << " ";
    }
    std::cout << std::endl;

    return 0;
}
