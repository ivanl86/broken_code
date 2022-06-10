

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

std::string getFileName(std::string prompt);
void openFile(std::string &fileName, std::ifstream &file);
void openFile(std::string &fileName, std::ofstream &file);
void processBuffers(char buf[], char otp[], int qty);
void xorOperation(std::ifstream &input, std::ifstream &otp, std::ofstream &out);

int main(int argc, char const *argv[])
{
    std::string inFileName{getFileName("Enter input file name: ")};
    std::string otpFileName{getFileName("Enter OTP file name: ")};
    std::string outFileName{getFileName("Enter output file name: ")};

    std::ifstream in;
    std::ifstream otp;
    std::ofstream out;

    try
    {
        openFile(inFileName, in);
        openFile(otpFileName, otp);
        openFile(outFileName, out);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    xorOperation(in, otp, out);

    std::cout << "File en/decrypted successfully!\n";
    return 0;
}

std::string getFileName(std::string prompt)
{
    std::string fileName;
    std::cout << prompt;
    std::getline(std::cin, fileName);
    return fileName;
}

void openFile(std::string &fileName, std::ifstream &file)
{
    file.open(fileName, std::ios::binary);
    if (!file)
        throw std::runtime_error("failed to open file");
    
}

void openFile(std::string &fileName, std::ofstream &file)
{
    file.open(fileName, std::ios::binary);
    if (!file)
        throw std::runtime_error("failed to open file");
    
}

void processBuffers(char buf[], char otp[], int qty)
{
    for (size_t i = 0; i < qty; ++i)
        buf[i] ^= otp[i];
}

void xorOperation(std::ifstream &input, std::ifstream &otp, std::ofstream &out)
{
    const static int bufSize{10240};
    char inBuf[bufSize];
    char otpBuf[bufSize];
    int qty;

    while (input)
    {
        input.read(inBuf, bufSize);
        qty = input.gcount();
        otp.read(otpBuf, qty);
        processBuffers(inBuf, otpBuf, qty);
        out.write(inBuf, qty);
    }
}
