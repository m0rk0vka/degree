#include "temp.h"
#include <ctime>
#include <fstream>

int main() {

    unsigned int start_time =  clock();
    
    //single b part
    /*
    int n;

    std::cin >> n;

    std::vector<std::vector<Fraction > > A_f (n, std::vector<Fraction > (n));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A_f[i][j] = Fraction(BigNumber(1), BigNumber(i + j + 1));
        }
    }
    std::cout << "find solution for single right part." << std::endl;

    std::string filename = str::itoa(n) + "_answer.txt";
    std::ofstream fout(filename);
    
    std::vector<Fraction> b_f (n, Fraction(BigNumber(1),BigNumber(1)));
    std::vector<Fraction > x_f = gaussFraction(A_f, b_f);
    for (auto el : x_f) {
        fout << el << "\n";
    }

    std::cout << "reverse check." << std::endl;

    std::vector<std::vector<Fraction> > xx_f (n, std::vector<Fraction> (1));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 1; j++) {
            xx_f[i][j] = x_f[i];
        }
    }
    filename = str::itoa(n) + "_check.txt";
    std::ofstream ffout(filename);
    std::vector<std::vector<Fraction> > bb_f = grapeFraction(A_f, xx_f);
    for (auto vec : bb_f) {
        for (auto el : vec) {
           ffout << el << " ";
        }
        ffout << std::endl;
    }*/

    //single solution
    int n;

    std::cin >> n;

    std::vector<std::vector<Fraction > > A_f (n, std::vector<Fraction > (n));

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            A_f[i][j] = Fraction(BigNumber(1), BigNumber(i + j + 1));
        }
    }

    std::cout << "find right (b) part if we have single solution." << std::endl;
    
    std::vector<std::vector<Fraction> > x_f (n, std::vector<Fraction> (1, Fraction(BigNumber(1),BigNumber(1))));
    std::vector<std::vector<Fraction> > b_f = grapeFraction(A_f, x_f);

    std::string filename = str::itoa(n) + "_answer_ss.txt";
    std::ofstream fout(filename);

    std::vector<Fraction> xx_f;

    for (auto vec : b_f) {
        for(auto el : vec) {
            fout << el << "\n";
            xx_f.push_back(el);
        }
    }

    std::cout << "check with gauss method to find single solution." << std::endl;

    filename = str::itoa(n) + "_check_ss.txt";
    std::ofstream ffout(filename);

    std::vector<Fraction> bb_f = gaussFraction(A_f, xx_f);
    for (auto el : bb_f) {
        ffout << el << "\n";
    }

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << "work time = " << search_time / CLOCKS_PER_SEC << " seconds" << std::endl;
}