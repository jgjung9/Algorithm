#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array
{
private:
    T *data;
    size_t n;

public:
    dynamic_array(int n)
    {
        this->n = n;
        data = new T[n];
    }

    dynamic_array(const dynamic_array<T> &other)
    {
        n = other.size();
        data = new T[n];

        for (int i = 0; i < n; i++)
            data[i] = other[i];
    }

    ~dynamic_array()
    {
        delete[] data;
    }

    size_t size() const { return n; }
    T *begin() { return data; }
    const T *begin() const { return data; }
    T *end() { return data + n; }
    const T *end() const { return data + n; }

    T &operator[](int index)
    {
        return data[index];
    }

    const T &operator[](int index) const
    {
        return data[index];
    }

    T &at(int index)
    {
        if (index < n)
            return data[index];
        throw std::out_of_range("Index out of range");
    }

    friend dynamic_array<T> operator+(const dynamic_array<T> &arr1, dynamic_array<T> &arr2)
    {
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    std::string to_string(const std::string &sep = ", ")
    {
        if (n == 0)
            return "";

        std::ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++)
            os << sep << data[i];

        return os.str();
    }
};

struct student
{
    std::string name;
    int standard;
};

std::ostream &operator<<(std::ostream &os, const student &s)
{
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
    int nStudents;
    std::cout << "1반 학생 수를 입력하시오: ";
    std::cin >> nStudents;

    dynamic_array<student> class1(nStudents);
    for (int i = 0; i < nStudents; i++)
    {
        std::string name;
        int standard;
        std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
        std::cin >> name >> standard;
        class1[i] = student{name, standard};
    }

    try
    {
        class1.at(nStudents) = student{"John", 8};
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }

    auto class2 = class1;
    std::cout << "1반을 복사하여 2반 생성: " << class1.to_string() << std::endl;

    auto class3 = class1 + class2;
    std::cout << "1반과 2반을 합쳐 3반 생성: " << class3.to_string() << std::endl;

    return 0;
}