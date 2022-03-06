#ifndef F15E00E8_8AA8_461F_AEFA_53C299C4779D
#define F15E00E8_8AA8_461F_AEFA_53C299C4779D
#include <chrono>
#include <sstream>
#include <string>

class TimeIt
{
private:
    std::chrono::steady_clock::time_point begin_;
    std::chrono::steady_clock::time_point end_;
    const std::string caller_;
    const std::uint32_t repeatation_;

public:
    TimeIt(const std::string &caller, std::uint32_t repeatation)
        : caller_(caller), begin_(std::chrono::steady_clock::now()), repeatation_(repeatation) {}
    ~TimeIt() {}
    void start() { begin_ = std::chrono::steady_clock::now(); }
    void stop()
    {
        end_ = std::chrono::steady_clock::now();
        auto t = (end_ - begin_);
        std::cout << caller_ << " time: " << (end_ - begin_).count() / repeatation_ << " nano seconds\n";
    }
};

#endif /* F15E00E8_8AA8_461F_AEFA_53C299C4779D */
