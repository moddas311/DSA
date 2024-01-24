#include <iostream>
#include <string>

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        std::string S;
        std::cin >> S;

        int maxZeros = 0;
        int currentZeros = 0;

        // Process the string and perform operations
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '0')
            {
                currentZeros++;
            }
            else
            {
                maxZeros = std::max(maxZeros, currentZeros);
                currentZeros = 0;
            }
        }

        // Handle the case where the string ends with '0'
        maxZeros = std::max(maxZeros, currentZeros);

        std::cout << maxZeros << "\n";
    }

    return 0;
}
